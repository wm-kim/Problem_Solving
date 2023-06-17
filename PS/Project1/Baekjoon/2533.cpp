#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, u, s;
vector<int> adj[1000001];
int dp[1000001][2];
bool pre[1000001];
void dfs(int start, int parent)
{
	pre[start] = true;
	dp[start][0] = 0;
	dp[start][1] = 1;
	
	for (int i = 0; i < adj[start].size(); i++)
	{
		int next = adj[start][i];
		if (next != parent && !pre[next])
		{
			dfs(next, start);
			dp[start][0] += dp[next][1];
			dp[start][1] += min(dp[next][0], dp[next][1]);
		}
	}
}

int main()
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> u >> s;
		adj[u].push_back(s);
		adj[s].push_back(u);
	}
	dfs(1, 0);
	cout << min(dp[1][0], dp[1][1]);
}

// i를 root로 하는 서브트리에서 최소 필요한 early adapter의 수 (dp[i][0]: i가 어댑터가 아닌 경우, dp[i][1]: i가 어댑터인 경우)
