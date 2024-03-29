#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, u, s, pop[10001], dp[10001][2];
vector<int> adj[10001];
bool pre[10001];
void dfs(int start, int parent)
{
	pre[start] = true;
	dp[start][0] = 0;
	dp[start][1] = pop[start];

	for (int next : adj[start])
	{
		if (next != parent && !pre[next])
		{
			dfs(next, start);
			dp[start][0] += max(dp[next][0], dp[next][1]);
			dp[start][1] += dp[next][0];
		}
	}
}
int main()
{
	cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N; for (int i = 1; i <= N; i++) cin >> pop[i];
	for (int i = 0; i < N - 1; i++)
	{
		cin >> u >> s;
		adj[u].push_back(s);
		adj[s].push_back(u);
	}
	dfs(1, 0);
	cout << max(dp[1][0], dp[1][1]) << '\n';
}