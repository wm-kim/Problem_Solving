// 조합 탐색

// 외판원 - 아무런 최적하도 하지 않았을 때
// 전역 변수에 지금까지 찾은 최적해의 길이를 저장해 두면 가지를 쳐내기 쉬워짐

#include <vector>
#include <algorithm>
using namespace std;

const double INF = 1e200;
const int MAX = 30;
int n;
double dist[MAX][MAX];
double best;

// 지금까지 구한 최적해와 같거나 더 나쁠 때 탐색을 중단하기

void search(vector<int>& path, vector<bool>& visited, double currentLength) {
	// 간단한 가지치기 : 지금까지 찾은 가장 좋은 답 이상일 경우 중단
	if (best <= currentLength) return;
	int here = path.back();
	if (path.size() == n) {
		best = min(best, currentLength + dist[here][0]);
		return;
	}
	for (int next = 0; next < n; ++next) {
		if (visited[next]) continue;
		path.push_back(next);
		visited[next] = true;
		search(path, visited, currentLength + dist[here][next]);
		visited[next] = false;
		path.pop_back();
	}
}
double solve() {
	best = INF;
	vector<bool> visitd(n, false);
	vector<int> path(1, 0);
	visitd[0] = true;

	search(path, visitd, 0);
	return best;
}


// 휴리스틱 이용
// 아직 방문하지 않은 도시들에 대해 인접한 간선중 가장 짧은 간선의 길이 더하기
// 이렇게 하면 최단 경로 이하의 값이 될 수 밖에 없다.
// 남은 도시를 방문하는 방법이 꼭 일렬로 연결된 형태가 아니어도 됨

double minEdge[MAX];
double SimpleHueristic(vector<bool>& visited) {
	double ret = minEdge[0]; // 마지막에서 시작점으로 돌아갈때 사용할 간선
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			ret += minEdge[i];
		}
	}
	return ret;
}

void search2(vector<int>& path, vector<bool>& visited, double currentLength) {
	if (best <= currentLength + SimpleHueristic(visited)) return;
	// ...
}

double solve2() {
	for (int i = 0; i < n; ++i) {
		minEdge[i] = INF;
		for (int j = 0; j < n; ++j)
			if (i != j) minEdge[i] = min(minEdge[i], dist[i][j]);
	}
	// ...
}

// 가까운 도시부터 방문하기
// 재귀적으로 다음에 어디를 방문할지 결정할 때 가까운 것 부터 방문하면 좋은 답을 빠르게 찾아낼 수 있는 경우가 있음
// 거리순으로 미리 정렬

vector<int> nearest[MAX];
void search3(vector<int>& path, vector<bool>& visited, double currentLength) {
	//

	for (int i = 0; i < nearest[here].size(); ++i) {
		int next = nearest[here][i];
	}
	//
}

double solve3() {
	for (int i = 0; i < n; i++) {
		vector<pair<double, int>> order;
		for (int j = 0; j < n; ++j) {
			if (i != j) {
				order.push_back(make_pair(dist[i][j], j));
			}
		}
		sort(order.begin(), order.end());
		nearest[i].clear();
		for (int j = 0; j < n - 1; ++j) {
			nearest[i].push_back(order[j].second);
		}
	}
	// 
}

