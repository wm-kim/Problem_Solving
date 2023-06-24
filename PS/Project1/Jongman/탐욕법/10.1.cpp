// 회의실 배정
#include <vector>
#include <algorithm>
using namespace std;
int n;
int begin1[100], end1[100];
int schedule() {
	vector<pair<int, int>> order;
	for (int i = 0; i < n; ++i) {
		order.push_back(make_pair(end1[i], begin1[i]));
	}
	sort(order.begin(), order.end());
	int earlist = 0, selected = 0;
	for (int i = 0; i < order.size(); ++i) {
		int meetingBegin = order[i].second, meetingEnd = order[i].first;
		if (earlist <= meetingBegin) {
			earlist = meetingEnd;
			++selected;
		}
	}
	return selected;
}

// 동적 계획법 접근
// schedule(idx) : meetings[idx] 혹은 그 이전에 끝나는 회의들 중 선택할 수 있는 최대 회의 수
// before[idx] : idx회의가 시작하기 전에 끝나는 회의들중 마지막 회의 번호
// schedule(inx) = (idx선택) ? 1 + schedule(before[idx]) : schedule(idx-1)