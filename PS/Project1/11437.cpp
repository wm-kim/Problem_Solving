#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int N, M, a, b, st[17][100001], depth[100001];
vector<int> graph[100001];
void dfs(int cur, int dep)
{
	depth[cur] = dep;
	for (int next : graph[cur])
	{
		if (depth[next] == -1)
		{
			st[0][next] = cur;
			dfs(next, dep + 1);
		}
	}
}
int lca(int a, int b)
{
	if (depth[a] > depth[b]) swap(a, b);
	int diff = depth[b] - depth[a];
	for (int i = 0; diff; i++)
	{
		if (diff % 2) b = st[i][b];
		diff /= 2;
	}
	if (a == b) return a;
	// a != b
	for (int i = 16; i >= 0; i--)
	{
		if (st[i][a] != st[i][b])
		{
			a = st[i][a];
			b = st[i][b];
		}
	}
	return st[0][a];
}
int main()
{
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		
	}
	memset(depth, -1, sizeof(depth));
	dfs(1, 0);
	for (int i = 1; i < 17; i++)
		for (int j = 1; j <= N; j++)
			st[i][j] = st[i - 1][st[i - 1][j]];
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		cout << lca(a, b) << "\n";
	}
}

// depth also can be used as visited