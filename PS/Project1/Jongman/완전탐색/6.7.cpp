// 여행하는 외판원 완전탐색
// 한 도시에서 출발해 다른 도시를 모두 방문 후 돌아올 때 가장 짧은 경로
#include <vector>
using namespace std;
const int MAX = 100;
const int INF = 987654321;
int n;
double dist[MAX][MAX];

double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength) {
	if (path.size() == n)
		return currentLength + dist[path[0]][path.back()];
	double ret = INF;
	for (int next = 0; next < n; ++next) {
		if (visited[next]) continue;
		int here = path.back();
		path.push_back(next);
		visited[next] = true;
		double cand = shortestPath(path, visited, currentLength + dist[here][next]);
		ret = min(ret, cand);
		visited[next] = false;
		path.pop_back();
	}
	return ret;
}
