// 3, 6, 9, 12 를 모두 12시를 가르키도록 바꾸기.
// 스위치를 누를때마다 해당 스위치와 연결된 시계들이 3시간씩 앞으로 움직임 
// - 최소한 스위치를 몇번 눌러야할까

// 12시가 지나면 제자리로 돌아온다는 것에서 조합의 수는 유한하게 바꿀 수 있다.
// 스위치를 누르는 순서는 전혀 중요하지 않다.

#include <vector>
using namespace std;

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;
const char linked[SWITCHES][CLOCKS + 1] = {};
// 'x' - 연결

// 모든 시계가 12시를 가리크고 있는지 확인
bool areAligned(const vector<int>& clocks);

// switch번 스위치 누른다.
void push(vector<int>&clocks, int swtch) {
	for (int clock = 0; clock < CLOCKS; ++clock) {
		if (linked[swtch][clock] == 'x') {
			clocks[clock] += 3;
			if (clocks[clock] == 15) clocks[clock] = 3;
		}
	}
}

// swtch는 이번에 눌를 스위치의 번호
int solve(vector<int>& clocks, int swtch) {
	if (swtch == SWITCHES) return areAligned(clocks) ? 0 : INF;
	int ret = INF;
	// 0~3번까지 누를 수 있음
	for (int cnt = 0; cnt < 4; ++cnt) {
		ret = min(ret, cnt + solve(clocks, swtch + 1));
		push(clocks, swtch);
	}

	return ret;
}
