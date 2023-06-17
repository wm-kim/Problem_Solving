#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int dist[300][300];
int T, I, cnt;
int dx[] = { -2,-2,-1,-1,1,1,2,2 }, dy[] = { -1,1,-2,2,-2,2,-1,1 };
struct Pos { int x, y; };
void bfs(Pos p)
{
	dist[p.y][p.x] = ++cnt;
	queue<Pos> q; q.push(p);

	while (!q.empty())
	{
		int cx = q.front().x, cy = q.front().y; q.pop();
		for (int i = 0; i < 8; i++)
		{
			int nx = cx + dx[i], ny = cy + dy[i];
			if (nx < 0 || nx >= I || ny < 0 || ny >= I || dist[ny][nx]) continue;
			dist[ny][nx] = dist[cy][cx] + 1;
			q.push({ nx,ny });
		}
	}
}
int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	cin >> T;
	while (T--)
	{
		cin >> I;
		for (int i = 0; i < I; i++) for (int j = 0; j < I; j++) dist[i][j] = 0;
		cnt = 0;
		int x, y, tx, ty; cin >> x >> y >> tx >> ty;
		bfs({ x,y }); cout << dist[ty][tx] - 1 << '\n';
	}
}