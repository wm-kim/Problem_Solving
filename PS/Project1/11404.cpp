#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1e9
using namespace std;
struct Edge { int from, to, cost; };
vector<Edge> v;
int dist[101][101];
int n, m, a, b, c;
void FloydWarshall()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}

	for (int i = 0; i < m; i++)
	{
		auto [from, to, cost] = v[i];
		dist[from][to] = min(dist[from][to], cost);
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		v.push_back({ a,b,c });
	}
	FloydWarshall();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dist[i][j] == INF) cout << 0 << " ";
			else cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
}