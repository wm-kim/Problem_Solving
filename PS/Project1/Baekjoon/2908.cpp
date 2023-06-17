#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1e9
using namespace std;
int N, w[16][16], ans = INF;
int dp[16][1 << 16];
int dfs(int last, int visited)
{
	if (visited == (1 << N) - 1)
	{
		if (w[last][0]) return w[last][0];
		else return INF;
	}
	if (dp[last][visited]) return dp[last][visited];
	dp[last][visited] = INF;
	for (int next = 0; next < N; next++)
	{
		if (visited & (1 << next) || !w[last][next]) continue;
		dp[last][visited] = min(dp[last][visited], dfs(next, visited | (1 << next)) + w[last][next]);
	}
	return dp[last][visited];
}

int main()
{
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	cin >> N; for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> w[i][j];
	cout << dfs(0, 1);
}