// n개의 정수 수열에서  왼쪽 또는 오른쪽에서 1개를 가져가거나 또는 2개를 삭제 할 수 있음. 
// 모두 최선을 다할 때, 최종 점수차는?

// play (state) 남은 수들이 state일 때 점수 차의 최대치
#include <iostream>
using namespace std;

const int EMPTY = -9876654321;
int n, board[50];
int cache[50][50];

int play(int left, int right) {
	if (left > right) return 0;
	int& ret = cache[left][right];
	if (ret != EMPTY) return ret;
	// 수를 가져가는 경우
	ret = max(board[left] - play(left + 1, right), board[right] - play(left, right - 1));
	// 삭제하는 경우
	if (right - left + 1 >= 2) {
		ret = max(ret, -play(left + 2, right));
		ret = max(ret, -play(left, right - 2));
	}
	return ret;
}

