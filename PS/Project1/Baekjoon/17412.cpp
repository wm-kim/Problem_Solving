#include <iostream>
#include <queue>
#include <vector>
#define MAX 401
using namespace std;
int N, P, c[MAX][MAX], f[MAX][MAX], pre[MAX], result;
vector<int> adj[MAX];
void edmonsKarp(int start, int end)
{
	while (1) {
		queue<int> q; q.push(start);
		fill(pre, pre + MAX, -1);
		while (!q.empty())
		{
			int cur = q.front(); q.pop();
			for (int i = 0; i < adj[cur].size(); i++) {
				int next = adj[cur][i];
				if (c[cur][next] - f[cur][next] > 0 && pre[next] == -1) {
					q.push(next);
					pre[next] = cur;
					if (next == end) break;
				}
			}
		}
		if (pre[end] == -1) break;
		for (int i = end; i != start; i = pre[i])
		{
			// 정방향은 + flow
			f[pre[i]][i] += 1;
			// 역방향은 - flow
			f[i][pre[i]] -= 1;
		}
		result += 1;
	}
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> N >> P;
	for (int i = 0; i < P; i++)
	{
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		// 음의 유량을 고려하기 위해서 필요
		adj[b].push_back(a);
		// 단방향 간선은 간선이 갖고 있는 방향으로만 용량을 할당한다.
		c[a][b] = 1;
	}
	edmonsKarp(1, 2);
	cout << result;
}