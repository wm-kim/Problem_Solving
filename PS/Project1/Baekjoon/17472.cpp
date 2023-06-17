#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, ans;
struct Pos { int x, y; };
struct Edge { Pos from, to; int cost; };
int grid[11][11]; bool pre[11][11], isBorder[11][11];
Pos pre[11][11]; int rnk[11][11];
int dx[] = { 0,0,-1,1 }, dy[] = { -1,1,0,0 };
vector<Edge> edges;
bool cmp(const Edge& a, const Edge& b) { return a.cost < b.cost; }
bool operator==(const Pos& a, const Pos& b) { return a.x == b.x && a.y == b.y; }
bool operator!=(const Pos& a, const Pos& b) { return !(a == b); }
Pos find(Pos p)
{
	if (pre[p.y][p.x] == p) return p;
	else return pre[p.y][p.x] = find(pre[p.y][p.x]);
}
void merge(Pos a, Pos b)
{
	a = find(a); b = find(b);
	if (a == b) return;
	if (rnk[a.y][a.x] > rnk[b.y][b.x]) pre[b.y][b.x] = a;
	else {
		pre[a.y][a.x] = b;
		if (rnk[a.y][a.x] == rnk[b.y][b.x]) rnk[b.y][b.x]++;
	}
}
void dfs(Pos start)
{
	pre[start.y][start.x] = true;
	bool border = false;
	for (int i = 0; i < 4; i++)
	{
		int nx = start.x + dx[i], ny = start.y + dy[i];
		if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
		if (grid[ny][nx] == 1 && !pre[ny][nx])
		{
			pre[ny][nx] = start;
			dfs({ nx,ny });
		}
		else if (grid[ny][nx] == 0) border = true;
	}
	if (border) isBorder[start.y][start.x] = true;
}

void kruskal()
{
	sort(edges.begin(), edges.end(), cmp);
	for (int i = 0; i < edges.size(); i++)
	{
		Pos from = edges[i].from, to = edges[i].to;
		if (find(from) == find(to)) continue;
		merge(from, to);
		ans += edges[i].cost;
	}
}
bool checkAllConnected() {
	Pos firstIsland = { -1, -1 }; 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (grid[i][j] == 1) {
				if (firstIsland == Pos{-1, -1}) firstIsland = { j, i };
				else {
					Pos currentIsland = { j, i };
					if (find(firstIsland) != find(currentIsland)) return false; 
				}
			}
		}
	}
	return true;
}
int main()
{
	cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> grid[i][j];
			if (grid[i][j] == 1) { pre[i][j] = { j,i }; rnk[i][j] = 1; }
		}
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (grid[i][j] == 1 && !pre[i][j]) dfs({ j,i });

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (isBorder[i][j])
				for (int dir = 0; dir < 4; dir++)
				{
					int length = 0; Pos to = { j,i };
					while (to.x + dx[dir] >= 0 && to.x + dx[dir] < M && to.y + dy[dir] >= 0 && to.y + dy[dir] < N)
					{
						to.x += dx[dir]; to.y += dy[dir];
						if (grid[to.y][to.x] == 1) break;
						length++;
					}
					if (length >= 2 && grid[to.y][to.x] == 1) edges.push_back({ {j,i},to,length });
				}
	kruskal();
	if (checkAllConnected()) cout << ans;
	else cout << -1;
}

//Pos moveToBorder(Pos p, int dx, int dy)
//{
//	Pos res = p;
//	while (res.x + dx >= 0 && res.x + dx < M && res.y + dy >= 0 && res.y + dy < N)
//	{
//		res.x += dx; res.y += dy;
//		if (grid[res.y][res.x] == 0) return { res.x - dx, res.y - dy };
//	}
//	return res;
//}

/*for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (grid[i][j] == 1)
			{
				for (int dir = 0; dir < 4; dir++)
				{
					Pos boarder = moveToBorder({ j,i }, dx[dir], dy[dir]);
					int length = 0; Pos to = boarder;
					while (to.x + dx[dir] >= 0 && to.x + dx[dir] < M && to.y + dy[dir] >= 0 && to.y + dy[dir] < N)
					{
						to.x += dx[dir]; to.y += dy[dir];
						if (grid[to.y][to.x] == 1) break;
						length++;
					}
					if (length >= 2 && grid[to.y][to.x] == 1) edges.push_back({ {j,i},to,length });
				}
			}*/