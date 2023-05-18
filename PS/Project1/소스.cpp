#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
using namespace std;
int cnt, order[100001], visited[100001] = { false };
void bfs(vector<set<int>>& graph, int r)
{
	visited[r] = true;
	order[r] = ++cnt;
	queue<int> q; q.push(r);
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (auto& next : graph[cur])
		{
			if (!visited[next])
			{
				visited[next] = true;
				order[next] = ++cnt;
				q.push(next);
			}
		}
	}
}
int main()
{
	int N, M, R; cin >> N >> M >> R;
	vector<set<int>> graph(N + 1);
	while (M--) {
		int from, to; cin >> from >> to;
		graph[from].insert(to);
		graph[to].insert(from);
	}
	bfs(graph, R);
	for (int i = 1; i <= N; ++i) cout << order[i] << " ";
}