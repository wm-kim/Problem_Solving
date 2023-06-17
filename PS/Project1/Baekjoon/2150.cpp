#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define MAX 10001
using namespace std;
int V, E, A, B, id, d[MAX];
bool finished[MAX];
vector<int> adj[MAX];
vector<vector<int>> SCC;
stack<int> s;

int dfs(int x)
{
	d[x] = ++id;
	s.push(x);
	
	int parent = d[x];
	for (int i = 0; i < adj[x].size(); i++)
	{
		int next = adj[x][i];
		if (d[next] == 0) parent = min(parent, dfs(next));
		else if (!finished[next]) parent = min(parent, d[next]);
		// (!finished[next]),
		// 현재 노드 x에서 next로의 역방향 간선이 존재한다는 의미
	}

	if (parent == d[x])
	{
		vector<int> scc;
		while (1)
		{
			int t = s.top(); s.pop();
			scc.push_back(t);
			finished[t] = true;
			if (t == x) break;
		}
		SCC.push_back(scc);
	}
	return parent;
}
int main()
{
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	cin >> V >> E;
	for (int i = 0; i < E; i++) { cin >> A >> B; adj[A].push_back(B); }
	for (int i = 1; i <= V; i++)
		if (d[i] == 0) dfs(i);	
	cout << SCC.size() << "\n";
	for (int i = 0; i < SCC.size(); i++)
		sort(SCC[i].begin(), SCC[i].end());
	sort(SCC.begin(), SCC.end(), [](vector<int> a, vector<int> b) {return a[0] < b[0]; });
	for (int i = 0; i < SCC.size(); i++)
	{
		for (int j = 0; j < SCC[i].size(); j++)
			cout << SCC[i][j] << " ";
		cout << "-1\n";
	}
}