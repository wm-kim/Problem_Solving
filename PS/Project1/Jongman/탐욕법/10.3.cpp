// 전자레인지 한번에 하나의 도시락 데울 수 있음
// i 번쨰 도시락을 데우는 데 m_i초, 먹는데 e_i초
// 나눠서 데우지 못하며, 다 데우면 바로 먹는다.
// 첫 번째 도시락을 데우기 시작부터 모든 사람이 먹을 때까지의 최소 시간을 출력

// 탐욕
// 먹는데 오래 걸리는 도시락 부터 데우기

#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 20;
int n, e[MAX_N], m[MAX_N];

int heat() {
	vector<pair<int, int>> order;
	for (int i = 0; i < n; ++i) {
		order.push_back(make_pair(-e[i], i));
	}
	sort(order.begin(), order.end());
	int ret = 0, beginEat = 0;
	for (int i = 0; i < n; ++i) {
		int box = order[i].second;
		beginEat += m[box];
		ret = max(ret, beginEat + e[box]);
	}
	return ret;
}