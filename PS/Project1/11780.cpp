#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 1e9;
struct Bus { int to, cost; };
vector<Bus> v[101];
int n, m, a, b, c;
int dist[101][101]; 
vector<int> path[101][101];
void FloydWarshall()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}

	for (int i = 1; i <= n; i++)
		for (auto& bus : v[i])
		{
			if (dist[i][bus.to] > bus.cost)
			{
				dist[i][bus.to] = bus.cost;
				path[i][bus.to] = { i, bus.to };
			}
		}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = path[i][k];
					path[i][j].insert(path[i][j].end(), path[k][j].begin() + 1, path[k][j].end());
				}
			}
		
}
int main()
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	FloydWarshall();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) cout << (dist[i][j] == INF ? 0 : dist[i][j]) << " ";
		cout << "\n";
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dist[i][j] == INF) cout << "0\n";
			else
			{
				cout << path[i][j].size() << " ";
				for (auto& p : path[i][j])
					cout << p << " ";
				cout << "\n";
			}
		}
	}
}