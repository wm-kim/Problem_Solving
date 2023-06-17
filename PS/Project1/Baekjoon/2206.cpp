#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int grid[1001][1001];
int dist[1001][1001][2];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
int N, M, ans; 
struct Pos { int x, y, w; };
int bfs()
{
	dist[1][1][1] = 1;
	queue<Pos> q; q.push({ 1,1,1 });
	
	while (!q.empty())
	{
		int cx = q.front().x, cy = q.front().y, cw = q.front().w, cd = dist[cy][cx][cw]; 
		q.pop();
		if (cx == M && cy == N) return cd;

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i], ny = cy + dy[i];
			if (nx < 1 || nx > M || ny < 1 || ny > N) continue;
			//다음 칸이 벽이고 뚫을 수 있을 때
			if (grid[ny][nx] == 1 && cw == 1) {
				dist[ny][nx][0] = cd + 1;
				q.push({ nx,ny,0 });
			}
			//다음 칸이 벽이 아니고 방문하지 않았을 때
			else if (grid[ny][nx] == 0 && dist[ny][nx][cw] == 0) {
				dist[ny][nx][cw] = cd + 1;
				q.push({ nx,ny,cw });
			}
		}
	}
	return -1;
}
int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string s; cin >> s;
		for (int j = 1; j <= M; j++) {
			grid[i][j] = s[j - 1] - '0';
		}
	}
	cout << bfs();
}

/*
완전 탐색으로 모든 벽을 한 번씩 뚫고 bfs를 하는 방법은 시간 초과이기 때문에,
이 조건을 어떻게 풀어갈지 고민을 해야 한다.

[row][column][1] == 벽을 부수지 않은 상태에서의 해당 칸에 도착하는 데에 이동한 칸의 개수
[row][column][0] == 벽을 부순 상태에서의 해당 칸에 도착하는 데에 이동한 칸의 개수
*/