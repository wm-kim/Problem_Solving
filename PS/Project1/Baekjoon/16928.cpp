# if 0 // 
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
vector<int> graph[101];
int dist[101];
bool moving[101];
int N, M;
void bfs(int start)
{
	dist[start] = 0;
	queue<int> q;
	q.push(start);
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i];
			if (dist[next] == -1)
			{	
				// next size 1인경우는 99에서 100으로 가는 경우도 있기 때문에 안됨
				// 또한 moving[next]도 이미 cur가 사다리나 뱀을 타고 온 경우에 
				// 아예 큐에 포함시키지 말아야했다.
				if (moving[next] != 0) dist[next] = dist[cur];
				else dist[next] = dist[cur] + 1;
				if (next >= 100) continue;
				else q.push(next);
			}
		}
	}
}
int main()
{
	fill(dist, dist + 101, -1);
	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= 6; j++)
			if (i + j <= 100) graph[i].push_back(i + j);
	cin >> N >> M;
	while (N--)
	{
		int x, y; cin >> x >> y;
		graph[x].clear(); graph[x].push_back(y); 
		moving[x] = y;
	}
	while (M--)
	{
		int u, v; cin >> u >> v;
		graph[u].clear(); graph[u].push_back(v);
		moving[u] = v;
	}
	bfs(1); cout << dist[100];
}
#endif

#if 1
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int moving[101];
int dist[101];
int main()
{
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		int n1, n2;
		cin >> n1 >> n2;
		moving[n1] = n2;
	}
	for (int i = 0; i < m; ++i)
	{
		int n1, n2;
		cin >> n1 >> n2;
		moving[n1] = n2;
	}
	queue<int> q;
	memset(dist, -1, sizeof(dist));
	q.push(1);
	dist[1] = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 1; i <= 6; ++i)
		{
			int nx = x + i;
			if (nx > 100) continue;
			if (moving[nx] != 0) nx = moving[nx];
			if (dist[nx] == -1) {
				dist[nx] = dist[x] + 1;
				q.push(nx);
			}
		}
	}
	cout << dist[100] << "\n";
	return 0;
}
#endif
