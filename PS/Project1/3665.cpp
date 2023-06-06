#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int T, n, m, a, b, inDegree[501];
vector<int> graph[501];
void topologySort()
{
	int result[501];
	queue<int> q;
	for (int i = 1; i <= n; i++) if (inDegree[i] == 0) q.push(i);
	for (int i = 1; i <= n; i++)
	{
		if (q.empty()) { cout << "IMPOSSIBLE\n"; return; }
		int cur = q.front(); q.pop();
		result[i] = cur;
		int cnt = 0;
		for (int j = 0; j < graph[cur].size(); j++)
		{
			int next = graph[cur][j];
			if (--inDegree[next] == 0) {
				cnt++; q.push(next);
			}
		}
		if (cnt > 1) { cout << "?\n"; return; }
	}
	for (int i = 1; i <= n; i++) cout << result[i] << " ";
	cout << "\n";
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++) { graph[i].clear(); inDegree[i] = 0; }
		vector<int> team(n + 1);
		for (int i = 1; i <= n; i++) cin >> team[i];
		for (int i = 1; i < n; i++) 
			for (int j = i + 1; j <= n; j++) {
				graph[team[i]].push_back(team[j]);
				inDegree[team[j]]++;
			}
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b;
			if (find(graph[a].begin(), graph[a].end(), b) != graph[a].end())
			{
				graph[a].erase(find(graph[a].begin(), graph[a].end(), b));
				graph[b].push_back(a);
				inDegree[a]++; inDegree[b]--;
			}
			else
			{
				graph[b].erase(find(graph[b].begin(), graph[b].end(), a));
				graph[a].push_back(b);
				inDegree[b]++; inDegree[a]--;
			}
		}
		topologySort();
	}
}

// queue에 한번에 하나씩 들어가므로 q.size() > 1로 확인 할 수도 있다.
// a가 앞에온다고해서 a가 b보다 순서가 높다는 보장이 없다.
// bool graph[501][501]로 하기도 한다.

// 따라서 { graph[team[i]].push_back(team[i + 1]); inDegree[team[i + 1]]++; } 
// 이렇게만 코드를 작성하면, 각 팀원이 바로 앞 팀원보다만 먼저 왔음을 표현할 뿐, 
// 그 이외의 관계는 무시하게 됩니다. 
// 이렇게 되면 앞선 팀원과 뒤따르는 팀원 간의 모든 대소 관계를 표현할 수 없게 됨