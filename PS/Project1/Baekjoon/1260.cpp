#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
vector<int> adj[1001];
bool dist[1001];
int N, M, V;
void dfs(int v)
{
	dist[v] = true;
	cout << v << " ";
	for (auto i : adj[v])
		if (!dist[i]) dfs(i);
}
void bfs(int v)
{
	dist[v] = true;
	cout << v << " ";
	queue<int> q; q.push(v);
	while (!q.empty())
	{
		int x = q.front(); q.pop();
		for (auto i : adj[x])
			if (!dist[i]) { 
				dist[i] = true; 
				cout << i << " ";
				q.push(i); 
			}
	}
}
int main()
{
	cin >> N >> M >> V;
	while (M--)
	{
		int from, to; cin >> from >> to;
		adj[from].push_back(to); adj[to].push_back(from);
	}
	for (int i = 1; i <= N; i++) sort(adj[i].begin(), adj[i].end());
	dfs(V); cout << "\n";
	for (int i = 1; i <= N; i++) dist[i] = false;
	bfs(V); cout << "\n";
}