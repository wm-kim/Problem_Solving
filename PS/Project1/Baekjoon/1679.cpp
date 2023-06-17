#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int dist[100001];
int N, K, sec = 1;
void bfs(int n)
{
	dist[n] = sec;
	queue<int> q; q.push(n);
	
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		int nsec = dist[cur] + 1;
		if (cur == K) return;
		if (cur - 1 >= 0 && !dist[cur - 1]) { dist[cur - 1] = nsec; q.push(cur - 1); }
		if (cur + 1 <= 100000 && !dist[cur + 1]) { dist[cur + 1] = nsec; q.push(cur + 1); }
		if (cur * 2 <= 100000 && !dist[cur * 2]) { dist[cur * 2] = nsec; q.push(cur * 2); }
	}
}
int main()
{
	cin >> N >> K;
	bfs(N); cout << dist[K] - 1;
}