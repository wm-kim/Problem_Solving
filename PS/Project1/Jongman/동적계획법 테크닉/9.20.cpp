// 조합 게임
// top-down 재귀 호출 알고리즘

// winer (state, player) : 게임의 현재 상태가 state,고 player가 수를 둘 차례일 때 어느쪽이 최종적으로 이길지?
// 게임 판의 상태만 보고 누가 둘차례인지 판별할 수 없는 경우 player를 전달

// canwin (state) : 현재 상태가 state일 때, 이번수를 둘 차례인 참가자가 이길지?
// 게임 트리를 그릴 수 있는 경우 ( 지난 상태로 다시 돌아갈 수 없는 게임)

// 틱택토
// canWin(board) 이번 차례인 사람이 이길 수있으면 1, 비기면 0, 질수 밖에 없으면 -1

// turn이 필요없긴한데 넣으면 구현이 간단해짐. 메모이제이션에는 포함시키지 않음
// 모든 것을 시도하면서 반환값 중 가장 작은 값을 찾음 (-1 이 없으면 0 ..)

#include <vector>
#include <string>
using namespace std;
bool isFinished(const vector<string>& board, char turn); // turn이 한줄을 만들었는지 반환
int bijection(const vector<string>& board) { // 보드를 정수로 변환, 일대일 대응 함수
	int ret = 0; 
	for (int y = 0; y < 3; ++y)
	{
		for (int x = 0; x < 3; ++x)
		{
			ret = ret * 3;
			if (board[y][x] == 'o') ++ret;
			else if (board[y][x] == 'x') ret += 2;
		}
	}
	return ret;
}

int cache[19683]; // -2로 초기화
int canWin(vector<string>& board, char turn) {
	// 기저 사례 : 마지막에 상대가 둬서 한줄이 만들어진 경우
	if (isFinished(board, 'o' + 'x' - turn)) return -1;
	int& ret = cache[bijection(board)];
	if (ret != -2) return ret;
	int minValue = 2;
	for (int y = 0; y < 3; ++y) {
		for (int x = 0; x < 3; ++x) {
			if (board[y][x] == '.') {
				board[y][x] = turn;
				minValue = min(minValue, canWin(board, 'o' + 'x' - turn));
				board[y][x] = '.';
			}
		}
	}
	// 플레이를 할 수 없거나 어떻게 해도 비기는것이 최선인 경우
	if (minValue == 2 || minValue == 0) return 0;
	return ret = -minValue;
}

// 보드를 뒤집거나 회전해도 같은 상태이기 때문에 이를 사용하여 더 빠르게 만들 수 있다.