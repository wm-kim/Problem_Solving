// 남극 기지 n개의 탐사 기지
// n개의 무전기를 기지에 배치해 연락망 구축, 거리가 d이하여야하고 모든 기지간에 서로 연결 가능해야함.
// 

// optimize(P) : 가능한 최소 무전기 통신 반경
// decision(P, d) : 모든 기지를 하나로 연결하되, 가장 먼 두기지 간의 거리가 d 이하인 연락망

// bfs 사용

#include <vector>
#include <queue>
using namespace std;

int n;
double dist[101][101];

// 거리 d 이하인 기지들만 연결 했을 때 모든 기지가 연결되는지 여부를 판단한다.
bool decision(double d) {
	vector<bool> visited(n, false);
	visited[0] = true;

	queue<int> q;
	q.push(0);
	int seen = 0;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		++seen;
		for (int there = 0; there < n; ++there) {
			if (!visited[there] && dist[here][there] <= d) {
				visited[there] = true;
				q.push(there);
			}
		}
	}
	return seen == n;
 }

double optimize() {
	double lo = 0, hi = 1416.00;
	for (int it = 0; it < 100; ++it) {
		double mid = (lo + mid) / 2;
		if (decision(mid)) hi = mid;
		else lo = mid;
	}
	return hi;
}

