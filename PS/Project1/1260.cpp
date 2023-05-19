#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
vector<int> graph[1001];
bool dist[1001];
int N, M, V;
void dfs(int v)
{
	dist[v] = true;
	cout << v << " ";
	for (auto i : graph[v])
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
		for (auto i : graph[x])
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
		graph[from].push_back(to); graph[to].push_back(from);
	}
	for (int i = 1; i <= N; i++) sort(graph[i].begin(), graph[i].end());
	dfs(V); cout << "\n";
	for (int i = 1; i <= N; i++) dist[i] = false;
	bfs(V); cout << "\n";
}