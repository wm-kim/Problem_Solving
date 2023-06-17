#if 0
#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <vector>
using namespace std;
int N, K, a, b, w, D, E, depth[100001], st[17][100001];
map<int, int> adj[100001];
void dfs(int cur, int dep)
{
	depth[cur] = dep;
	for (auto next : adj[cur])
	{
		if (depth[next.first] == -1)
		{
			st[0][next.first] = cur;
			dfs(next.first, dep + 1);
		}
	}
}
tuple<int, int> lca(int a, int b)
{
	cout << "a depth " << depth[a] << " b depth " << depth[b] << "\n";
	if (depth[a] > depth[b]) swap(a, b);
	int mincost = 1e9, maxcost = 0;
	for (int i = 16; i >= 0; i--)
		if (depth[a] <= depth[st[i][b]])
		{
			mincost = min(mincost, adj[b][st[i][b]]);
			maxcost = max(maxcost, adj[b][st[i][b]]);
			b = st[i][b];
		}
	
	if (a == b) return { mincost, maxcost };
	
	for (int i = 16; i >= 0; i--)
		if (st[i][a] != st[i][b])
		{
			mincost = min({ mincost, adj[a][st[i][a]], adj[b][st[i][b]] });
			maxcost = max({ maxcost, adj[a][st[i][a]], adj[b][st[i][b]] });
			a = st[i][a];
			b = st[i][b];
		}
	
	mincost = min({ mincost, adj[a][st[0][a]], adj[b][st[0][b]] });
	maxcost = max({ maxcost, adj[a][st[0][a]], adj[b][st[0][b]] });
	return { mincost, maxcost };
}

int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b >> w;
		adj[a][b] = w;
		adj[b][a] = w;
	}
	memset(depth, -1, sizeof(depth));
	dfs(1, 0);
	for (int i = 1; i < 17; i++)
		for (int j = 1; j <= N; j++)
			st[i][j] = st[i - 1][st[i - 1][j]];
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> D >> E;
		auto [mincost, maxcost] = lca(D, E);
		cout << mincost << ' ' << maxcost << '\n';
	}
}

// tie(mincost, maxcost) = lca(D, E);

#endif

#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <vector>
using namespace std;
int N, K, a, b, w, D, E, depth[100001], st[17][100001];
int minpath[17][100001], maxpath[17][100001];
struct Edge { int to, cost; };
vector<Edge> adj[100001];
void dfs(int cur, int dep, int cost)
{
	depth[cur] = dep;
	minpath[0][cur] = maxpath[0][cur] = cost;
	for (auto next : adj[cur])
	{
		if (depth[next.to] == -1)
		{
			st[0][next.to] = cur;
			dfs(next.to, dep + 1, next.cost);
		}
	}
}
tuple<int, int> lca(int a, int b)
{
	int mincost = 1000001, maxcost = 0;
	if (depth[a] > depth[b]) swap(a, b);
	int diff = depth[b] - depth[a];
	for (int i = 0; diff; i++, diff >>= 1)
		if (diff & 1)
		{
			mincost = min(mincost, minpath[i][b]);
			maxcost = max(maxcost, maxpath[i][b]);
			b = st[i][b];
		}

	if (a == b) return { mincost, maxcost };
	
	for (int i = 16; i >= 0; i--)
		if (st[i][a] != 0 && st[i][a] != st[i][b])
		{
			mincost = min({ mincost, minpath[i][a], minpath[i][b] });
			maxcost = max({ maxcost, maxpath[i][a], maxpath[i][b] });
			a = st[i][a];
			b = st[i][b];
		}
	mincost = min({ mincost, minpath[0][a], minpath[0][b] });
	maxcost = max({ maxcost, maxpath[0][a], maxpath[0][b] });
	return { mincost, maxcost };
}

int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b >> w;
		adj[a].push_back({ b, w });
		adj[b].push_back({ a, w });
	}
	memset(depth, -1, sizeof(depth));
	memset(minpath, 1000001, sizeof(minpath));
	memset(maxpath, 0, sizeof(maxpath));
	
	dfs(1, 0, 0);
	
	for (int i = 1; i < 17; i++)
		for (int j = 1; j <= N; j++)
		{
			st[i][j] = st[i - 1][st[i - 1][j]];
			minpath[i][j] = min(minpath[i - 1][j], minpath[i - 1][st[i - 1][j]]);
			maxpath[i][j] = max(maxpath[i - 1][j], maxpath[i - 1][st[i - 1][j]]);
		}
	
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> D >> E;
		auto [mincost, maxcost] = lca(D, E);
		cout << mincost << ' ' << maxcost << '\n';
	}
}

// MAX[k][i] : i의 2^k번쨰 부모까지의 최대값
// MIN[k][i] : i의 2^k번쨰 부모까지의 최솟값