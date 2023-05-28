#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
const int MAX = 100000;
using namespace std;
int N, K; 
int visited[MAX + 1], pre[MAX + 1];
void bfs(int start)
{
	queue<int> q; q.push(start);
	visited[start] = 0;

	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		if (cur == K) return;
		if (cur - 1 >= 0 && visited[cur - 1] == -1) { q.push(cur - 1); visited[cur - 1] = visited[cur] + 1; pre[cur - 1] = cur; }
		if (cur + 1 <= MAX && visited[cur + 1] == -1) { q.push(cur + 1); visited[cur + 1] = visited[cur] + 1; pre[cur + 1] = cur; }
		if (cur * 2 <= MAX && visited[cur * 2] == -1 ) { q.push(cur * 2); visited[cur * 2] = visited[cur] + 1; pre[cur * 2] = cur; }
	}
}
int main()
{
	cin >> N >> K;
	fill(visited, visited + MAX + 1, -1);
	bfs(N); cout << visited[K] << "\n";
	vector<int> ans;
	for (int i = K; i != N; i = pre[i]) ans.push_back(i);
	ans.push_back(N);
	for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
}