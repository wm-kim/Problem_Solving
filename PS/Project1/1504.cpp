#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 1e9
using namespace std;
struct Edge { int to, cost; };
int N, E, a, b, c, v1, v2, ans = INF;
vector<Edge> adj[801];
int dist[801]; bool visited[801];
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
		for (int i = 0; i < (int)adj[cur].size(); i++)
		{
			int next = adj[cur][i].to;
			int nextDist = adj[cur][i].cost;
			if (dist[next] > dist[cur] + nextDist)
			{
				dist[next] = dist[cur] + nextDist;
				pq.push({ -dist[next], next });
			}
		}
	}
}

int main()
{
	cin >> N >> E;
	while (E--)
	{
		cin >> a >> b >> c;
		adj[a].push_back({ b, c }); adj[b].push_back({ a, c });
	}
	cin >> v1 >> v2;
	Dijkstra(1); int StoV1 = dist[v1], StoV2 = dist[v2];
	Dijkstra(v1); int V1toV2 = dist[v2], V1toN = dist[N];
	Dijkstra(v2); int V2toN = dist[N];
	ans = min(ans, StoV1 + V1toV2 + V2toN);
	ans = min(ans, StoV2 + V1toV2 + V1toN);
	if (V1toV2 == INF || ans == INF) cout << -1;
	else cout << ans;
}