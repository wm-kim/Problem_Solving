#include <iostream>
#include <vector>
using namespace std;
int n; int c = 0;
int chess[15][15] = { 0, };

// My Answer
#if 0
bool isValid(int x, int y)
{
	for (int i = 0; i < n; i++)
	{
		if (chess[y][i] == 1) return false;
		if (chess[i][x] == 1) return false;
	}
	for (int i = x, j = y; i >= 0 && j >= 0; i--, j--)
		if (chess[j][i] == 1) return false;
	for (int i = x, j = y; i < n && j < n; i++, j++)
		if (chess[j][i] == 1) return false;
	for (int i = x, j = y; i >= 0 && j < n; i--, j++)
		if (chess[j][i] == 1) return false;
	for (int i = x, j = y; i < n && j >= 0; i++, j--)
		if (chess[j][i] == 1) return false;
	return true;
}

void printChess()
{
	for (int i = 0; i < n; i++)
	{
		cout << "[";
		for (int j = 0; j < n; j++)
		{
			cout << chess[i][j] << " ";
		}
		cout << "]" << endl;
	}
	return;
}

void backtracking(int depth)
{
	if (depth == n) {
		// print chess board
		cout << "board " << ++c << endl;
		printChess();
	}

	// 각 깊이에서 모든 행과 열에 대해 퀸을 배치하려고 시도
	// 4 * 3 * 2 * 1 = 24, 24 * 2 = 48
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (!isValid(x, y)) continue;
			cout << "depth: " << depth << " x: " << x << " y: " << y << endl;
			printChess();
			chess[y][x] = 1;
			backtracking(depth + 1);
			chess[y][x] = 0;
		}
	}
}

int main() {
	cin >> n;
	backtracking(0);
	cout << c;
}
#endif

// GPT 각 행에 퀸을 하나씩 만 배치, 깊이와 행을 일치시켜 각 행에 퀸을 하나씩만 배치
# if 0
bool isValid(int x, int y)
{
	for (int i = 0; i < y; i++)
	{
		if (chess[i][x] == 1) return false;
	}

	for (int i = x, j = y; i >= 0 && j >= 0; i--, j--)
		if (chess[j][i] == 1) return false;

	for (int i = x, j = y; i < n && j >= 0; i++, j--)
		if (chess[j][i] == 1) return false;

	return true;
}

void backtracking(int depth)
{
	if (depth == n) { c++; return; }

	for (int x = 0; x < n; x++)
	{
		if (!isValid(x, depth)) continue;
		chess[depth][x] = 1;
		backtracking(depth + 1);
		chess[depth][x] = 0;
	}
}

int main() {
	cin >> n;
	backtracking(0);
	cout << c;
}
#endif

#if 0
#include <iostream>
#define MAX 15
using namespace std;

int col[MAX]; // N인 일차원 배열을 만든 후, 각 열에 몇번째 행의 퀸이 있는지를 저장
int N, total = 0;

bool check(int level)
{
	for (int i = 0; i < level; i++)
		if (col[i] == col[level] || abs(col[level] - col[i]) == level - i)// 대각선이거나 같은 라인
			return false;
	//col[i]가 의미하는 것이 X좌표, i가 의미하는것이 Y좌표이므로 차이가 일정하다면 대각선에 있다고 볼 수 있다.
	return true;
}

void nqueen(int x)
{
	if (x == N)
		total++;
	else
	{
		for (int i = 0; i < N; i++)
		{
			col[x] = i; // 해당 위치에 퀸을 배치
			if (check(x)) // 유효하다면 다음행의 퀸 배치, 유효하지않다면 다른 위치로 퀸 배치 변경
				nqueen(x + 1);
		}
	}
}
int main() {
	cin >> N;
	nqueen(0);
	cout << total;
}
#endif

#define MAX 15
using namespace std;

int ch[MAX];
int N, cnt = 0;

bool valid(int level)
{
	for (int i = 0; i < level; i++)
		if (ch[i] == ch[level] || abs(ch[level] - ch[i]) == level - i)
			return false;
	return true;
}

void bt(int x)
{
	if (x == N) cnt++;
	else
	{
		for (int i = 0; i < N; i++)
		{
			ch[x] = i;
			if (valid(x)) bt(x + 1);
		}
	}
}
int main() {
	cin >> N; bt(0); cout << cnt;
}