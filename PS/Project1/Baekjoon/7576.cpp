#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int box[1001][1001]; int dist[1001][1001];
int M, N, ans;
int dx[] = { 0,0,-1,1 }, dy[] = { -1,1,0,0 };
struct Pos { int x, y, d; };
void bfs(vector<Pos>& v)
{
	queue<Pos> q;
	for (auto p : v)
	{
		dist[p.y][p.x] = 1;
		q.push({ p.x,p.y, 1 });
	}

	while (!q.empty())
	{
		int cx = q.front().x, cy = q.front().y, cd = q.front().d;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i], ny = cy + dy[i], nd = cd + 1;
			if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
			if (dist[ny][nx] != 0 || box[ny][nx] == -1) continue;
			dist[ny][nx] = nd;
			box[ny][nx] = 1; // 익은 토마토로 변경
			q.push({ nx,ny,nd });
		}
	}
}

int main()
{
	cin >> M >> N; vector<Pos> v;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
	{
		cin >> box[i][j]; if (box[i][j] == 1) v.push_back({ j,i });
	}
	bfs(v);
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++)
		{
			if (box[i][j] == 0) { cout << -1; return 0; }
			ans = max(ans, dist[i][j]);
		}
	if (ans == 1) cout << 0;
	else cout << ans - 1;
}