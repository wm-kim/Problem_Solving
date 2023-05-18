#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
int cnt, order[100001], visited[100001] = { false };
void dfs(vector<set<int>>& graph, int r)
{
	visited[r] = true;
	order[r] = ++cnt;
	for (auto node : graph[r])
		if (!visited[node]) dfs(graph, node);
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
	dfs(graph, R);
	for (int i = 1; i <= N; ++i) cout << order[i] << " ";
}