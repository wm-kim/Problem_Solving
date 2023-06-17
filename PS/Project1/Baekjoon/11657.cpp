#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1e9
using namespace std;
int N, M, A, B, C;
struct Edge { int from, to, cost; };
vector<Edge> adj;
long long dist[501]; 
bool BellmanFord(int start)
{
	fill(dist, dist + 501, INF);
	dist[start] = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < adj.size(); j++)
		{
			auto [from, to, cost] = adj[j];
			if (dist[from] != INF && dist[to] > dist[from] + cost)
				dist[to] = dist[from] + cost;
		}
	}

	for (int i = 0; i < adj.size(); i++)
	{
		auto [from, to, cost] = adj[i];
		if (dist[from] != INF && dist[to] > dist[from] + cost)
			return false;
	}
	return true;
}
int main()
{
	cin >> N >> M;
	while (M--)
	{
		cin >> A >> B >> C;
		adj.push_back({ A, B, C });
	}
	if (BellmanFord(1))
	{
		for (int i = 2; i <= N; i++)
			if (dist[i] == INF) cout << -1 << "\n";
			else cout << dist[i] << "\n";
	}
	else cout << -1 << "\n";
}

// if 문안에 dist[from] != INF가 필요한 이유 : 
// 출발 노드에서 도달할 수 있는 정점들만 relaxation을 수행하도록 하기 위한 것입니다.