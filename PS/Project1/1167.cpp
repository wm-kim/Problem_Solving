#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int V, from, to, cost;
struct Edge { int to, cost; };
vector<Edge> graph[100001];
int dist[100001];
void bfs(int start) {
	memset(dist, -1, sizeof(dist));
	queue<int> q;
	q.push(start);
	dist[start] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto& next : graph[cur]) {
			if (dist[next.to] == -1) {
				dist[next.to] = dist[cur] + next.cost;
				q.push(next.to);
			}
		}
	}
}
int main()
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> V;
	for (int i = 1; i <= V; i++)
	{
		cin >> from;
		while (1) {
			cin >> to;
			if (to == -1) break;
			cin >> cost;
			graph[from].push_back({ to, cost });
		}
	}
	bfs(1);
	int start = 1;
	for (int i = 2; i <= V; i++)
		if (dist[i] > dist[start]) start = i;
	bfs(start);
	int ans = 0;
	for (int i = 1; i <= V; i++) ans = max(ans, dist[i]);
	cout << ans;
}

/*
트리의 지름을 찾는 문제에서는 BFS를 두 번 사용하는 것이 일반적
트리의 특정 점에서 가장 먼 점을 찾은 후, 
그 점에서 다시 가장 먼 점을 찾으면 그 두 점 사이의 거리가 트리의 지름

visited 배열과 dist 배열 모두 필요합니다.
하지만 이 두 가지 정보를 동시에 저장하는 구조를 사용하면 코드를 좀 더 간결하게 만들 수 있습니다. 
예를 들어, 각 노드까지의 거리를 -1로 초기화하고, 방문하지 않은 노드의 거리를 -1로 두는 방법
*/