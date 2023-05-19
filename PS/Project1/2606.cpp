#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> graph[101];
bool dist[101] = { false };
int n, e, cnt;
void dfs(int v)
{
	dist[v] = true;
	for (auto i : graph[v])
		if (!dist[i]) dfs(i);
}
int main()
{
	cin >> n >> e;
	while (e--)
	{
		int from, to; cin >> from >> to;
		graph[from].push_back(to); graph[to].push_back(from);
	}
	dfs(1);
	for (int i = 2; i <= n; i++) if (dist[i]) cnt++;
	cout << cnt;
}