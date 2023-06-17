#include <iostream>
#include <vector>
using namespace std;
#define N 9
int board[N][N] = { 0, };
vector<pair<int, int>> pos; // 0의 위치를 저장
bool found = false;

bool valid(int x, int y, int num)
{
	for (int i = 0; i < N; i++) {
		if (board[y][i] == num || board[i][x] == num)
			return false;
	}	

	int nx = x / 3; int ny = y / 3;
	for (int i = ny * 3; i < ny * 3 + 3; i++) {
		for (int j = nx * 3; j < nx * 3 + 3; j++) {
			if (board[i][j] == num)
				return false;
		}
	}
	return true;
}

void sudoku(int n)
{
	if (n == pos.size()) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << board[i][j] << " ";
			} cout << "\n";
		}
		found = true;
		return; 
	}

	for (int i = 1; i <= 9; i++) {
		int x = pos[n].first; int y = pos[n].second;
		if (valid(x, y, i)) {
			board[y][x] = i; 
			sudoku(n + 1); 
			if (found) return;
			board[y][x] = 0;
		}
	}
}

int main()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> board[y][x];
			if (board[y][x] == 0) pos.push_back({ x, y });
		}
	}
	sudoku(0);
}