#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 32000
using namespace std;
int N, M, inDegree[MAX+1];
vector<int> adj[MAX+1];

void topologySort()
{
	int result[MAX + 1];
	queue<int> q;
	for (int i = 1; i <= N; i++) if (inDegree[i] == 0) q.push(i);
	for (int i = 1; i <= N; i++)
	{
		if (q.empty()) return;
		int cur = q.front(); q.pop();
		result[i] = cur;
		for (int j = 0; j < adj[cur].size(); j++)
		{
			int next = adj[cur][j];
			if (--inDegree[next] == 0) q.push(next);
		}
	}
	for (int i = 1; i <= N; i++) cout << result[i] << " ";
}	

int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		inDegree[b]++;
	}
	topologySort();
}