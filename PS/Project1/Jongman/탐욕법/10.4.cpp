// 문자열 합치기, n개의 문자열을 순서 상관없이 한개의 문자열로 만들기
// 합치는 비용 - 두 문자열의 합, 비용 최소화

// 탐욕 - 항상 짧은 두 문자열 부터 합치기


#include <vector>
#include <queue>
using namespace std;

int concat(const vector<int>& lengths) {
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < lengths.size(); i++) {
		pq.push(lengths[i]);
	}
	int ret = 0;
	while (pq.size() > 1) {
		int min1 = pq.top(); pq.pop();
		int min2 = pq.top(); pq.pop();
		pq.push(min1 + min2);
		ret += min1 + min2;
	}
	return ret;
}