#if 0
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int T, N, K, d[1001], indegree[1001], dp[1001], ans;
vector<int> adj[1001];
void bfs(int cur)
{
	queue<int> q;
	q.push(cur);
	dp[cur] = d[cur];
	
	while (!q.empty())
	{
		int x = q.front(); q.pop();
		for (int i = 0; i < adj[x].size(); i++)
		{
			int next = adj[x][i];
			dp[next] = max(dp[next], dp[x] + d[next]);
			q.push(next);
		}
	}
}
int main()
{
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> K;
		for (int i = 1; i <= N; i++) adj[i].clear();
		for (int i = 1; i <= N; i++) 
		{ 
			cin >> d[i]; 
			indegree[i] = 0; 
			dp[i] = 0;
		}
		for (int i = 1; i <= K; i++)
		{
			int a, b; cin >> a >> b;
			adj[a].push_back(b);
			indegree[b]++;
		}
		cin >> K;
		for (int i = 1; i <= N; i++)
			if (indegree[i] == 0) bfs(i);
		cout << dp[K] << "\n";
	}
}
#endif

// indegree가 0인 노드 부터 bfs를 돌려야 한다. 
// 건설 순서는 모든 건물이 건설 가능하도록 주어지기 때문에 시작 노드를 제외한
// 모든 노드는 indegree가 1 이상이다.

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int T, N, K, d[1001], indegree[1001], dp[1001], ans;
vector<int> adj[1001];
void tpsort() {
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			dp[i] = d[i];
		}
	}
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = 0; i < adj[x].size(); i++) {
			int next = adj[x][i];
			indegree[next]--;
			dp[next] = max(dp[next], dp[x] + d[next]);
			if (indegree[next] == 0)
				q.push(next);
		}
	}
}
int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> N >> K;
		for (int i = 1; i <= N; i++) {
			adj[i].clear();
			cin >> d[i];
			indegree[i] = 0;
			dp[i] = 0;
		}
		for (int i = 1; i <= K; i++) {
			int a, b; cin >> a >> b;
			adj[a].push_back(b);
			indegree[b]++;
		}
		tpsort();
		int W; cin >> W;
		cout << dp[W] << "\n";
	}
}