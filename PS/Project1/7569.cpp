#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int box[101][101][101]; int dist[101][101][101];
int M, N, H, ans;
int dx[] = { 0, 0, 0, 0, 1, -1 }, dy[] = { 0, 0, 1, -1, 0, 0 }, dz[] = { 1, -1, 0, 0, 0, 0 };
struct Pos { int x, y, z, d; };
void bfs(vector<Pos>& v)
{
	queue<Pos> q;
	for (auto p : v)
	{
		dist[p.z][p.y][p.x] = 1;
		q.push({ p.x,p.y,p.z,1 });
	}

	while (!q.empty())
	{
		int cx = q.front().x, cy = q.front().y, cz = q.front().z, cd = q.front().d; 
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int nx = cx + dx[i], ny = cy + dy[i], nz = cz + dz[i];
			if (nx < 0 || nx >= M || ny < 0 || ny >= N || nz < 0 || nz >= H) continue;
			if (dist[nz][ny][nx] || box[nz][ny][nx] == -1) continue;
			dist[nz][ny][nx] = 1;
			box[nz][ny][nx] = 1;
			q.push({ nx,ny,nz,cd + 1 });
			ans = max(ans, cd + 1); // 주의
		}
	}
}

int main()
{
	cin >> M >> N >> H; vector<Pos> v;
	for (int k = 0; k < H; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) {
				cin >> box[k][i][j];
				if (box[k][i][j] == 1) v.push_back({ j,i,k,0 });
			}
	bfs(v);
	for (int k = 0; k < H; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) {
				if (!dist[k][i][j] && box[k][i][j] == 0) {
					cout << -1; return 0;
				}
			}
	if (ans == 0) cout << 0;
	else cout << ans - 1;
}