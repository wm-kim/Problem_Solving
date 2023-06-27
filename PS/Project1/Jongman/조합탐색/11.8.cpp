// 게임판 덮기 6.6 참고
// 게임판의 크기 (H, W) 블록 모양 격자의 크기 (R, C)
// 최대 몇개의 블록을 올려놓을 수 있는지 판단

#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<vector<pair<int, int>>> rotations;
int blockSize;
// 2차원 배열 arr 90도 회전
vector<string> rotate(const vector<string>& arr) {
	vector<string> ret(arr[0].size(), string(arr.size(), ' '));
	for (int i = 0; i < arr.size(); ++i) {
		for (int j = 0; j < arr[0].size(); ++j) {
			ret[j][arr.size() - i - 1] = arr[i][j];
		}
	}
	return ret;
}

// block 의 4가지 회전 형태를 만들고 상대 좌표 목록으로 변환
void generateRotations(vector<string> block) {
	rotations.clear();
	rotations.reserve(4);

	for (int rot = 0; rot < 4; ++rot) {
		int originY = -1, originX = -1;
		for (int i = 0; i < block.size(); ++i) {
			for (int j = 0; j < block.size(); ++j) {
				if (block[i][j] == '#') {
					// 가장 윗줄 왼쪽 있는 칸이 원점이 된다.
					if (originY == -1) {
						originY = i, originX = j;
					}
					rotations[rot].push_back(make_pair(i - originY, j - originX));
				}
			}
		}
		block = rotate(block);
	}

	// 네가지 회전형태중 중복이 있을 경우 제거
	sort(rotations.begin(), rotations.end());
	rotations.erase(unique(rotations.begin(), rotations.end()), rotations.end());
	// 블록이 몇칸 짜리인지 저장
	blockSize = rotations[0].size();
}

// (y. x)를 덮지 않기로 결정한 경우에도 막아둠
// 이렇게 하면 재귀호출 시에 원래 검은칸이었다고 인식되어 무시

int boardH, boardW;
vector<string> board;

int covered[10][10]; // 1이면 덮임, 0은 빈칸
int best; // 최적해

bool set(int y, int x, const vector<pair<int, int>>& block, int delta);

void search(int placed) {
	// 아직 채우지 못한 가장 윗줄 왼쪽에 있는 칸을 찾는다.
	int y = -1, x = -1;
	for (int i = 0; i < boardH; ++i) {
		for (int j = 0; j < boardW; ++j) {
			if (covered[i][j] == 0) {
				y = i, x = j; break;
			}
		}
		if (y != -1) break;
	}

	// 모든 판을 처리한 경우 (기저사례)
	if (y == -1) {
		best = max(best, placed);
		return;
	}

	for (int i = 0; i < rotations.size(); ++i) {
		if (set(y, x, rotations[i], 1))
		{
			search(placed + 1);
		}
		set(y, x, rotations[i], -1);
	}


	// 이 칸을 덮지 않고 막아둔다.
	covered[y][x] = 1;
	search(placed);
	covered[y][x] = 0;
}

int solve() {
	best = 0;
	// covered 배열 초기화
	for (int i = 0; i < boardH; ++i) {
		for (int j = 0; j < boardW; ++j) {
			covered[i][j] = (board[i][j] == '#' ? 1 : 0);
		}
	}
	search(0);
	return best;
}

// 가지치기
// 가장 큰 답을 찾는 문제의 휴리스틱은 과대평가한다. 
// 제약 없애기 - 블록을 통째로 내려놓아야한다는 제약을 없애서, 한칸씩 쪼개 놓을 수 있도록 변형
// 그러면 단순히 빈칸의 수 / 블록의 크기가 놓을 수 있는 블록의 수가 된다.