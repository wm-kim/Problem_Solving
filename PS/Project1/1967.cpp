#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
int N, p, c, w;
struct Edge { int to, w; };
vector<Edge> graph[10001];
int dist[10001], pre[10001];
void bfs(int start)
{
	memset(dist, -1, sizeof(dist));
	queue<int> q; q.push(start);
	dist[start] = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (Edge e : graph[cur]) {
			if (dist[e.to] == -1) {
				dist[e.to] = dist[cur] + e.w;
				q.push(e.to);
			}
		}
	}
}
int main()
{
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> p >> c >> w;
		graph[p].push_back({ c,w });
		graph[c].push_back({ p,w });
		pre[c] = p;
	}
	bfs(1); 
	int start = 1;
	for (int i = 2; i <= N; i++)
		if (dist[i] > dist[start]) start = i;
	bfs(start);
	int ans = 0;
	for (int i = 1; i <= N; i++)
		ans = max(ans, dist[i]);
	cout << ans;
}