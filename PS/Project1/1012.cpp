#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int T, M, N, K, X, Y;
int grid[50][50], dist[50][50];
int dx[] = { 0,0,-1,1 }, dy[] = { -1,1,0,0 };
void dfs(int x, int y)
{
	dist[y][x] = true;

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
		if (grid[ny][nx] == 0 || dist[ny][nx]) continue;
		dfs(nx, ny);
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> T;
	while (T--)
	{
		int ans = 0;
		cin >> M >> N >> K;
		// 주의 : 초기화 할 것
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j) {
				grid[i][j] = 0;
				dist[i][j] = 0;
			}
		while (K--) { cin >> X >> Y; grid[Y][X] = 1; }
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				if (grid[i][j] == 1 && !dist[i][j]) { dfs(j, i); ans++; }
		cout << ans << "\n";
	}
}