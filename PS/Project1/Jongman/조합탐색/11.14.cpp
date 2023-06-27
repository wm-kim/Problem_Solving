// 카구로
// 게임판의 크기 N, (0은 검은 칸 또는 힌트칸, 1은 흰칸) 
// 힌트의 수 Q (x,y,dir,sum) dir = 0 가로 힌트, dir = 1 세로힌트

// 항상 답이 하나 뿐이라 최적화문제는 아님 
// 제약 충족 문제 Constraint Satisfication Problem

// 최적화 기법들이 해당 되지 않음.
// Constraint porpogation
// 채울 순서 정하기 - 경우의 수가 적은 것 부터 (variable ordering, value ordering)


// getCandiates(len, sum, known[]) 
// 연속된 len개의 흰 칸안에 적힌 수의 합이 sum이어야 하는데 그 중 적힌 숫자의 목록이 known일 때 
// 남은 칸에 들어갈 수 있는 숫자들의 집합

// 비트 마스크 사용
#include <cstring>
using namespace std;

int getSize(int mask); //mask에 속한 원소들의 개수를 반환
int getSum(int mask); // mask에 속한 원소들의 합을 반환

int getCandidates(int len, int sum, int known) {
	// 조건들에 부합하는 집합들의 교집합
	int allSets = 0;
	// 1~9 부분 집합 , 모든 짝수를 생성하고 그중
	for (int set = 0; set < 1024; set += 2) {
		// known을 포함하고, 크기가 len이며 합이 sum인 집합을 모두 찾는다.
		if ((set & known) == known && getSize(set) == len && getSum(set) == sum) {
			allSets |= set;
		}
	}
	return allSets & ~known;
}

// 미리 계산해놓기 
int candidates[10][46][1024];
void generateCandiates() {
	memset(candidates, 0, sizeof(candidates));
	for (int set = 0; set < 1024; set += 2) {
		int l = getSize(set), s = getSum(set);
		int subset = set;
		while (true) {
			// 숫자 하나의 합이 s이고 이미 subset의 숫자가 쓰여있을때
			// 전체 숫자의 집합이 set이 되도록 나머지 숫자를 채워넣을 수 있다.
			candidates[l][s][subset] |= (set & ~subset);
			if (subset == 0) break;
			subset = (subset - 1) & set;
		}
	}
}

// 각 칸마다 힌트 2개를 배열에 미리 저장해두기
/// 그리고 힌드에 대해 해당하는 흰칸의 수와 쓰인 숫자들의 집합을 탐색과정에서 유지

const int MAXN = 10;
// color 각 칸의 색깔, value : 각 흰칸의 숫자, hint 각 칸에 해당하는 두 힌트의 번호 (위치)
int n, color[MAXN][MAXN], value[MAXN][MAXN], hint[MAXN][MAXN][2];
// sum 흰트 칸에 쓰인 숫자
// length 힌트칸에 해당하는 흰칸의 수, known 힌트 칸에 해당하는 흰칸에 쓰인 숫자들의 집합
int q, sum[MAXN * MAXN], length[MAXN * MAXN], known[MAXN * MAXN];

void put(int y, int x, int val) {
	for (int h = 0; h < 2; ++h) {
		known[hint[y][x][h]] += (1 << val);
	}
	value[y][x] = val;
}

void remove(int y, int x, int val) {
	for (int h = 0; h < 2; ++h) {
		known[hint[y][x][h]] -= (1 << val);
	}
	value[y][x] = 0;
}

// 힌트 번호가 주어질 때 후보의 집합을 반환한다.
int getCandHint(int hint) {
	return candidates[length[hint]][sum[hint]][known[hint]];
}
 
// 좌표가 주어질 때 해당 칸에 들어갈 수 있는 후보 집합 반환
int getCandCoord(int y, int x) {
	return getCandHint(hint[y][x][0]) & getCandHint(hint[y][x][1]);
}

// 후보수가 가장 적은 칸부터 채우기
void PrintSolution(); 

bool search() {
	// 아직 숫자를 쓰지 않은 흰칸 중에 후보수가 최소인 칸을 찾는다.
	int y = -1, x = -1, minCands = 1023;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (color[i][j] == WHITE && value[i][j] == 0) {
				int cands = getCandCoord(i, j);
				if (getSize(minCands) > getSize(cands)) {
					minCands = cands;
					y = i, x = j;
				}
			}
		}
	}
	// 이칸에 들어갈 숫자가 없다면 실패
	if (minCands == 0) return false;
	// 모든 칸이 채워졌으면 출력하고 종료한다.
	if (y == -1) {
		PrintSolution(); return true;
	}

	// 숫자를 하나씩 채워보자
	for (int val = 1; val <= 9; ++val) {
		if (minCands & (1 << val)) {
			put(y, x, val);
			if (search()) return true;
			remove(y, x, val);
		}
	}
	return false;
}