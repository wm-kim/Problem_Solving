// 외발 뛰기
// 사각 게임판 시작점에서 시작점에서 끝 점으로 도달하는 방법이 존재하는지 확인
// 각 칸에 적혀진 숫자만 큼 오른쪽이나 아래로 이동

int n, board[100][100];
 
bool jump(int y, int x) {
	if (y >= n || x >= n) return false;
	// 마지막 칸에 도착
	if (y == n - 1 && x == n - 1) return true;
	int jumpSize = board[y][x];
	return jump(y + jumpSize, x) || jump(y, x + jumpSize);
}

int cache[100][100];

// 메모이제이션
bool jump2(int y, int x) {
	if (y >= n || x >= n) return 0;
	if (y == n - 1 && x == n - 1) return true;
	int& ret = cache[y][x];
	if (ret != -1) return ret;
	int jumpSize = board[y][x];
	return jump2(y + jumpSize, x) || jump2(y, x + jumpSize);
}