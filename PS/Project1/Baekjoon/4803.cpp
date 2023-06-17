#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
bool pre[501];
vector<int> adj[501];
int N, m, idx;
bool IsCycle(int node, int parent)
{
	pre[node] = true;
	for (int i = 0; i < adj[node].size(); i++)
	{
		int next = adj[node][i];
		if (next == parent) continue;
		if (pre[next]) return true;
		if (IsCycle(next, node)) return true;
	}
	return false;
}

int IsTree()
{
	memset(pre, false, sizeof(pre));
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		if (!pre[i])
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
		for (int i = 1; i <= N; i++) adj[i].clear();
		for (int i = 0; i < m; i++)
		{
			int a, b; cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
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
