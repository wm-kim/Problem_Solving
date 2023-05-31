#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// dp[i][0]: 정점 i를 선택하지 않은 경우, dp[i][1]: 정점 i를 선택한 경우
int n; int w[10001], dp[10001][2];
bool visited[10001];
vector<int> graph[10001], ans;

void dfs(int start, int parent)
{
	visited[start] = true;
	dp[start][0] = 0;
	dp[start][1] = w[start];
	
	for (int i = 0; i < graph[start].size(); i++)
	{
		int next = graph[start][i];
		if (next != parent && !visited[next])
		{
			dfs(next, start);
			dp[start][0] += max(dp[next][0], dp[next][1]);
			dp[start][1] += dp[next][0];
		}
	}
}

void constructSet(int start, int parent, bool isParentSelected)
{
	if (!isParentSelected && dp[start][1] > dp[start][0])
	{
		ans.push_back(start);
		for (int child : graph[start])
			if (child != parent) constructSet(child, start, true);
	}
	else // isParentSelected || dp[start][1] <= dp[start][0]
		for (int child : graph[start])
			if (child != parent) constructSet(child, start, false);
}

int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	cin >> n; for (int i = 1; i <= n; i++) cin >> w[i];
	for (int i = 0; i < n - 1; i++)
	{
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1, 0);
	cout << max(dp[1][0], dp[1][1]) << '\n';
	constructSet(1, 0, false);
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
}

// 트리의 최대 독립 집합을 구하는 문제. 
// tree_dp + 역추적

/*
함수 내에서 자식 노드를 선택하거나 선택하지 않는 경우를 재귀 호출할 때, 이미 선택된 부모 노드가 있는 경우 해당 부모 노드를 선택하지 않는 것이 맞습니다. 
이를 보장하기 위해서는 재귀 호출 시에 부모 노드를 인자로 넘겨줘서 부모 노드를 선택하지 않는 경우에만 자식 노드를 선택하도록 제한할 수 있습니다.
*/
