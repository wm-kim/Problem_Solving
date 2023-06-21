// 게임 판 덮기
// 중복 해결 : 순서는 중요하지 않다. 가장 왼쪽에 있는 칸 부터 채우기
#include <vector>
using namespace std;

const int coverType[4][3][2] = {
	{ {0, 0}, {1, 0}, {0, 1} },
	{ {0, 0}, {0, 1}, {1, 1} },
	{ {0, 0}, {1, 0}, {1, 1} },
	{ {0, 0}, {1, 0}, {1, -1} }
};

// 겹치거나, 검은 칸을 덮을때 false 반환
bool set(vector<vector<int>>& board, int y, int x, int type, int delta) {
	bool ok = true;	
	for (int i = 0; i < 3; i++) {
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board.size())
			ok = false;
		else if ((board[ny][nx] += delta) > 1) ok = false;	
	}
	return ok;
}

int cover(vector<vector<int>>& board) {
	int y = -1, x = -1;
	// 가장 윗줄 왼쪽 부터 채움 
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board.size(); ++j)
		{
			if (board[i][j] == 0) { y = i; x = j; break; }
		}
		if (y != -1) break;
	}

	if (y == -1) return 1; // 모든 칸을 채움
	int ret = 0;
	for (int type = 0; type < 4; ++type) {
		// 덮을 수 있다면 재귀 호출
		if (set(board, y, x, type, 1)) {
			ret += cover(board);
		}
		// 덮었던 블록 치우기
		set(board, y, x, type, -1);
	}
	return ret;
}