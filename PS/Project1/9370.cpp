#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 1e9
#define MAX 2000
using namespace std;
int T, N, m, t, s, g, h, a, b, d, x;
struct Edge { int to, cost; };
vector<Edge> graph[MAX + 1];
int dist[MAX + 1]; bool visited[MAX + 1];
void Dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	fill(visited, visited + N + 1, false);
	fill(dist, dist + N + 1, INF);
	dist[start] = 0;
	
	while (!pq.empty())
	{
		int cur = pq.top().second; pq.pop();
		if (visited[cur]) continue;
		visited[cur] = true;
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].to;
			int nextCost = graph[cur][i].cost;
			if (dist[next] > dist[cur] + nextCost)
			{
				dist[next] = dist[cur] + nextCost;
				pq.push({ -dist[next], next });
			}
		}
	}
}
int main()
{
	cin >> T;
	while (T--)
	{
		cin >> N >> m >> t >> s >> g >> h;
		for (int i = 1; i <= N; i++) graph[i].clear();
		while (m--) 
		{ 
			cin >> a >> b >> d; 
			graph[a].push_back({ b, d }); graph[b].push_back({ a, d }); 
		}
		vector<int> targets;
		while (t--) { cin >> x; targets.push_back(x); }
		sort(targets.begin(), targets.end());
		Dijkstra(s); int sToG = dist[g], sToH = dist[h];
		vector<int> sToTargetDist;
		for (int i = 0; i < targets.size(); i++) sToTargetDist.push_back(dist[targets[i]]);
		Dijkstra((sToH > sToG) ? h : g);
		for (int i = 0; i < targets.size(); i++)
		{
			if (sToTargetDist[i] == max(sToG, sToH) + dist[targets[i]])
				cout << targets[i] << " ";
		}
		cout << "\n";
	}
}