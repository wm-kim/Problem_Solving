#if 0
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 32000
using namespace std;
int N, M;
int parent[MAX + 1], inDegree[MAX + 1];
vector<int> graph[MAX + 1];
int findParent(int x)
{
	if (parent[x] == x) return x;
	return parent[x] = findParent(parent[x]);
}
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
		for (int j = 0; j < graph[cur].size(); j++)
		{
			int next = graph[cur][j];
			if (--inDegree[next] == 0) q.push(next);
		}
	}
	for (int i = 1; i <= N; i++) cout << result[i] << " ";
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) parent[i] = i;
	for (int i = 1; i <= M; i++)
	{
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		inDegree[b]++;
		if (b < findParent(a)) parent[findParent(b)] = findParent(a);
		else parent[findParent(a)] = findParent(b);
	}
	for (int i = 1; i <= N; i++)
		for (int j = i + 1; j <= N; j++)
			if (findParent(i) < findParent(j))
			{
				graph[i].push_back(j);
				inDegree[j]++;
			}
	topologySort();
}
#endif

#include <iostream>
#include <vector>
#include <queue>
#define MAX 32000
using namespace std;
int N, M;
vector<int> adj[MAX + 1];
int inDegree[MAX + 1];
void topologySort() {
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) {
			pq.push(i);
		}
	}
	while (!pq.empty()) {
		int cur = pq.top();
		pq.pop();
		cout << cur << " ";
		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i];

			if (--inDegree[next] == 0) {
				pq.push(next);
			}
		}
	}
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		inDegree[b]++;
	}
	topologySort();
}
// 차수가 0인 정점에 있어서도 순서가 있기 때문에 
// 이를 우선순위 큐를 이용하여 풀면 된다.