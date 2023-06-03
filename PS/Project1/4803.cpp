#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
bool visited[501];
vector<int> graph[501];
int N, m, idx;
bool IsCycle(int node, int parent)
{
	visited[node] = true;
	for (int i = 0; i < graph[node].size(); i++)
	{
		int next = graph[node][i];
		if (next == parent) continue;
		if (visited[next]) return true;
		if (IsCycle(next, node)) return true;
	}
	return false;
}

int IsTree()
{
	memset(visited, false, sizeof(visited));
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])
			if (!IsCycle(i, 0)) cnt++;
	}
	return cnt;
}

int main()
{
	while (1)
	{
		cin >> N >> m;
		if (N == 0 && m == 0) break;
		for (int i = 1; i <= N; i++) graph[i].clear();
		for (int i = 0; i < m; i++)
		{
			int a, b; cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		int cnt = IsTree();
		idx++;
		if (cnt == 0) cout << "Case " << idx << ": No trees.\n";
		else if (cnt == 1) cout << "Case " << idx << ": There is one tree.\n";
		else cout << "Case " << idx << ": A forest of " << cnt << " trees.\n";
	}
}

// parent를 같이 넘겨주는 이유는, 
// previous node와 next node를 구분하기 위해서입니다.
// parent가 없는 경우 (root node)에는 parent를 0으로 설정합니다.
