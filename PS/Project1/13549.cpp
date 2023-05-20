#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 100000
using namespace std;
int N, K, ans;
struct Edge { int to, cost; };
vector<Edge> graph[MAX + 1];
int dist[MAX + 1];
bool visited[MAX + 1];
void Dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	dist[start] = 0;
	while (!pq.empty())
	{
		int cur = pq.top().second; pq.pop();
		if (visited[cur]) continue;
		visited[cur] = true;
		if (cur == K) return;
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].to;
			int cost = graph[cur][i].cost;
			if (dist[next] > dist[cur] + cost)
			{
				dist[next] = dist[cur] + cost;
				pq.push({ -dist[next], next });
			}
		}
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	fill(dist, dist + MAX + 1, 1e9);
	cin >> N >> K;
	for (int i = 0; i <= MAX; i++)
	{
		if (i + 1 <= MAX) graph[i].push_back({ i + 1, 1 });
		if (i - 1 >= 0) graph[i].push_back({ i - 1, 1 });
		if (i * 2 <= MAX) graph[i].push_back({ i * 2, 0 });
	}
	Dijkstra(N); cout << dist[K];
}

/* BFS를 이용한 풀이
#include <iostream>
#include <queue>
using namespace std;

int N, K;
int dist[100001];

int main() {
	cin >> N >> K;
	fill(dist, dist + 100001, -1);
	dist[N] = 0;
	deque<int> dq;
	dq.push_front(N);
	while (!dq.empty()) {
		int x = dq.front();
		dq.pop_front();
		if (x == K) {
			cout << dist[K];
			return 0;
		}
		// 주의할 점은 순간이동은 0초가 걸리므로, 순간이동을 먼저 처리
		if (x * 2 <= 100000 && dist[x * 2] == -1) {
			dist[x * 2] = dist[x];
			dq.push_front(x * 2);
		}
		if (x - 1 >= 0 && dist[x - 1] == -1) {
			dist[x - 1] = dist[x] + 1;
			dq.push_back(x - 1);
		}
		if (x + 1 <= 100000 && dist[x + 1] == -1) {
			dist[x + 1] = dist[x] + 1;
			dq.push_back(x + 1);
		}
	}
	return 0;
}
*/