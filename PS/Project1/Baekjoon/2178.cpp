#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int grid[100][100], dist[100][100];
int dx[] = { 0,0,1,-1 }, dy[] = { 1,-1,0,0 };
int N, M;
struct Pos { int x, y, d; };
void bfs(Pos p)
{
	dist[p.y][p.x] = p.d;
	queue<Pos> q; q.push(p);
	
	while (!q.empty())
	{
		int cx = q.front().x, cy = q.front().y, cd = q.front().d; q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = cx + dx[i], ny = cy + dy[i];
			if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
			if (dist[ny][nx] != 0 || grid[ny][nx] == 0) continue;
			dist[ny][nx] = cd + 1;
			q.push({ nx,ny,cd + 1 });
		}
	}
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		string s; cin >> s;
		for (int j = 0; j < M; ++j)
			grid[i][j] = s[j] - '0';
	}
	bfs({ 0,0,1 }); cout << dist[N - 1][M - 1];
}