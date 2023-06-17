#if 0
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int K, V, E;
vector<int> graph[20001];
bool visited[20001];
vector<int> groupA, groupB;
bool bipart()
{
	queue<pair<int, int>> q; q.push({ 1, 0 });
	visited[1] = true; groupA.push_back(1);

	while (!q.empty())
	{
		int cur = q.front().first; 
		int curGroup = q.front().second; q.pop();
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i];
			int nextGroup = (curGroup + 1) % 2;
			if (visited[next]) continue;
			visited[next] = true;
			if (nextGroup == 0) groupA.push_back(next);
			else groupB.push_back(next);
			q.push({ next, nextGroup });
		}
	}
	for (int i = 0; i < groupA.size(); i++)
	{
		int cur = groupA[i];
		for (int j = 0; j < graph[cur].size(); j++)
		{
			int next = graph[cur][j];
			if (find(groupA.begin(), groupA.end(), next) != groupA.end()) return false;
		}
	}
	for (int i = 0; i < groupB.size(); i++)
	{
		int cur = groupB[i];
		for (int j = 0; j < graph[cur].size(); j++)
		{
			int next = graph[cur][j];
			if (find(groupB.begin(), groupB.end(), next) != groupB.end()) return false;
		}
	}
	return true;
}

int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	cin >> K;
	while (K--)
	{
		for (int i = 1; i <= V; i++) { graph[i].clear(); visited[i] = false; }
		groupA.clear(); groupB.clear();
		
		cin >> V >> E;
		for (int i = 0; i < E; i++)
		{
			int u, v; cin >> u >> v;
			graph[u].push_back(v); graph[v].push_back(u);
		}
		cout << (bipart() ? "YES" : "NO") << '\n';
	}
}
#endif

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 20001;
int K, V, E, color[MAX];
vector<int> adj[MAX];

bool bfs(int start) {
	queue<int> q;
	color[start] = 1;
	q.push(start);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i];
			if (color[next] == 0) {
				color[next] = -color[cur];
				q.push(next);
			}
			else if (color[next] == color[cur]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> K;
	while (K--) {
		cin >> V >> E;
		for (int i = 1; i <= V; i++) {
			adj[i].clear(); color[i] = 0;
		}
		for (int i = 0; i < E; i++) {
			int u, v; cin >> u >> v;
			adj[u].push_back(v); adj[v].push_back(u);
		}
		bool bipartite = true;
		for (int i = 1; i <= V; i++) {
			if (color[i] == 0) {
				if (!bfs(i)) {
					bipartite = false;
					break;
				}
			}
		}
		cout << (bipartite ? "YES" : "NO") << '\n';
	}
	return 0;
}

/*
이 문제의 답변은 입력 그래프가 연결되어 있는지 여부에 따라 달라집니다. 
입력 그래프가 여러 개의 분리된 부분 그래프로 구성될 수 있다면, 
각 부분 그래프에 대해 BFS를 실행해야 합니다.
즉, 그래프가 연결되어 있지 않을 수 있다면, 모든 노드를 시작점으로 BFS를 수행해야 합니다. 
각각의 연결 요소를 확인하는 것이기 때문입니다.
*/