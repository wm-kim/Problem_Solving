#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
using namespace std;
int cnt, order[100001], dist[100001] = { false };
struct Compare { bool operator()(int a, int b) const { return a > b; } };
void bfs(vector<set<int, Compare>>& graph, int r)
{
	dist[r] = true;
	order[r] = ++cnt;
	queue<int> q; q.push(r);
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (auto& next : graph[cur])
		{
			if (!dist[next])
			{
				dist[next] = true;
				order[next] = ++cnt;
				q.push(next);
			}
		}
	}
}
int main()
{
	int N, M, R; cin >> N >> M >> R;
	vector<set<int, Compare>> graph(N + 1);
	while (M--) {
		int from, to; cin >> from >> to;
		graph[from].insert(to);
		graph[to].insert(from);
	}
	bfs(graph, R);
	for (int i = 1; i <= N; ++i) cout << order[i] << " ";
}