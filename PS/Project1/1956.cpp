#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1e9
using namespace std;
struct Edge { int from, to, cost; };
int dist[401][401];
int V, E, a, b, c, ans = INF;
int main()
{
	cin >> V >> E;
	for (int i = 1; i <= V; i++)
		for (int j = 1; j <= V; j++)
		{
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		dist[a][b] = c;
	}
	
	for (int k = 1; k <= V; k++)
		for (int i = 1; i <= V; i++)
			for (int j = 1; j <= V; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	for (int i = 1; i <= V; i++)
		for (int j = 1; j <= V; j++)
		{
			if (i == j) continue;
			ans = min(ans, dist[i][j] + dist[j][i]);
		}
	
	if (ans == INF) cout << -1;
	else cout << ans;
}