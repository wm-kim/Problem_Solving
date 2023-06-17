#if 0 // 우선순위 큐 삭제 삽입 시간초과
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int V, E, K, u, v, w;
struct Edge { int u, v, w; };
vector<Edge> graph[20001];
int dist[20001];
void Dijkstra(int start)
{
	// min-heap
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	fill(dist, dist + V + 1, 1e9);
	dist[start] = 0; 
	pq.push({ start, 0 });

	while (!pq.empty())
	{
		int cur = pq.top().first;
		int curDist = pq.top().second; 
		pq.pop();

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].v;
			int nextDist = curDist + graph[cur][i].w;
			if (dist[next] > nextDist)
			{
				dist[next] = nextDist;
				pq.push({ next, nextDist });
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> V >> E >> K;
	while (E--)
	{
		cin >> u >> v >> w; graph[u].push_back({ u, v, w });
	}
	Dijkstra(K);
	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == 1e9) cout << "INF\n";
		else cout << dist[i] << '\n';
	}
}
#endif 

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits>
using namespace std;
#define INF numeric_limits<int>::max()
struct Edge {int v, w;};
void Dijkstra(int start, int V, const vector<vector<Edge>>& graph, vector<int>& dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({ 0, start });
    while (!pq.empty()) {
        int cur = pq.top().second;
        int curDist = pq.top().first;
        pq.pop();

        if (curDist > dist[cur])
            continue;

        for (const auto& edge : graph[cur]) {
            int next = edge.v;
            int nextDist = curDist + edge.w;
            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({ nextDist, next });
            }
        }
    }
}
int main() {
    int V, E, K;
    cin >> V >> E >> K;
    vector<vector<Edge>> graph(V + 1);
    vector<int> dist(V + 1, INF);
    while (E--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({ v, w });
    }
    Dijkstra(K, V, graph, dist);
    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
}