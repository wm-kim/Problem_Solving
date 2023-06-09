#if 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define MAX 100001
using namespace std;
int T, N, M, x, y, id, ans, d[MAX], sccId[MAX], indegree[MAX];
bool finished[MAX];
vector<int> adj[MAX];
vector<vector<int>> SCC;
stack<int> s;
int dfs(int x)
{
	int parent = d[x] = ++id;
	s.push(x);
	for (int i = 0; i < adj[x].size(); i++)
	{
		int next = adj[x][i];
		if (d[next] == 0) parent = min(parent, dfs(next));
		else if (!finished[next]) parent = min(parent, d[next]);
	}

	if (parent == d[x])
	{
		vector<int> scc;
		while (1)
		{
			int t = s.top(); s.pop();
			scc.push_back(t);
			finished[t] = true;
			sccId[t] = SCC.size() + 1;
			if (t == x) break;
		}
		SCC.push_back(scc);
	}
	return parent;
}
int main()
{
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	cin >> T;
	while (T--)
	{
		ans = 0;
		cin >> N >> M;
		for (int i = 1; i <= N; i++) { adj[i].clear(); d[i] = 0; finished[i] = false; indegree[i] = 0; }
		SCC.clear();
		for (int i = 0; i < M; i++) { cin >> x >> y; adj[x].push_back(y); }
		for (int i = 1; i <= N; i++) if (d[i] == 0) dfs(i);
		for (int i = 1; i <= N; i++)
			for (auto j : adj[i])
				if (sccId[i] != sccId[j]) indegree[sccId[j]]++;
		for (int i = 1; i <= SCC.size(); i++) 
			if (!indegree[i]) ans++;
		cout << ans << "\n";
	}
}
#endif 

// idea : 각 정점마다 dfs를 돌려서 dfs가 호출되는 수를 구하기
// dfs가 호출되는 순서에 따라 cnt 가 달라질 수 있다. 
// indegree가 0인 SCC의 개수가 답


// 모든 정점의 연결을 살펴보면서 두 정점의 SCC가 다르다면 연결당하는 SCC의 indegree를 1 증가시켜준다.
// 그리고 모든 SCC의 indegree를 검사하면서 indegree값이 0인 SCC의 개수를 출력
