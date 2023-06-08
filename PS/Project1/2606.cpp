#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> adj[101];
bool dist[101] = { false };
int N, pre, cnt;
void dfs(int v)
{
	dist[v] = true;
	for (auto i : adj[v])
		if (!dist[i]) dfs(i);
}
int main()
{
	cin >> N >> pre;
	while (pre--)
	{
		int from, to; cin >> from >> to;
		adj[from].push_back(to); adj[to].push_back(from);
	}
	dfs(1);
	for (int i = 2; i <= N; i++) if (dist[i]) cnt++;
	cout << cnt;
}