#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, u, v, pop[10001], dp[10001][2];
vector<int> graph[10001];
bool visited[10001];
void dfs(int start, int parent)
{
	visited[start] = true;
	dp[start][0] = 0;
	dp[start][1] = pop[start];

	for (int next : graph[start])
	{
		if (next != parent && !visited[next])
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
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(1, 0);
	cout << max(dp[1][0], dp[1][1]) << '\n';
}