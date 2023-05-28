#if 0
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 1000;
int N, W, total_dist;
struct Pos { int x, y; };
int dp[MAX + 1][MAX + 1];
int dx[] = { 0,0,-1,1 }, dy[] = { -1,1,0,0 };
	int bfs(Pos start, Pos target)
	{
		queue<Pos> q; q.push(start);
		dp[start.y][start.x] = 1;

		for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) dp[i][j] = 0;
	
		while (!q.empty())
		{
			int cx = q.front().x, cy = q.front().y;
			q.pop();

			if (cx == target.x && cy == target.y) return dp[cy][cx] - 1;
		
			for (int i = 0; i < 4; i++)
			{
				int nx = cx + dx[i], ny = cy + dy[i];
				if (nx < 1 || nx > MAX || ny < 1 || ny > MAX) continue;
				if (dp[ny][nx] != 0) continue;
				dp[ny][nx] = dp[cy][cx] + 1;
				q.push({ nx,ny });
			}
		}
		return -1;
	}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> W;
	vector<Pos> v(W + 1); for (int i = 1; i <= W; i++) { cin >> v[i].x >> v[i].y; }
	Pos police1 = { 1,1 }, police2 = { N,N };
	vector<int> order;
	for (int i = 1; i <= W; i++)
	{
		int dist1 = bfs(police1, v[i]); int dist2 = bfs(police2, v[i]);
		if (dist1 < dist2) { police1 = v[i]; total_dist += dist1; order.push_back(1); }
		else { police2 = v[i]; total_dist += dist2; order.push_back(2); }
		cout << "total dist : " << total_dist << '\n';
	}

	cout << total_dist << "\n";
	for (auto o : order) cout << o << "\n";
}
#endif
/*
최소 거리의 경찰차만을 선택하는 Greedy 알고리즘으로 문제를 해결할 수 있을 것으로 생각하였다. 
하지만 그리디 알고리즘으로는 거리의 합의 최솟값을 얻을 수 없었다.
완전탐색을 적용하돼 Dynamic Programming을 통해서 시간 내에 문제를 해결할 수 있다.

DP idea : 점화식으로 표현하기 위해서는
거리의 합에 영향을 받는 부분은 현재 경찰차1,2의 위치이다. 
즉 그 위치는 각 경찰차가 마지막으로 맡은 사건의 위치이며 
그 위치 이전에 어느 곳을 방문했는지는 이후의 사건에 영향을 주지 못한다.
 2차원배열로 각 경찰차들의 최종 사건을 파라미터로 최소값을 저장하여 DFS에서 DP를 설계
 DFS를 DP를 위해 재귀함수로 구현

 dp : 경찰차들의 최종 사건을 파라미터로 거리 최소값

 현재 경찰차들의 마지막 사건번호 x,y 를 통해 해당 x,y일 때 이후에 최소거리를 만들 수 있는 경찰차를 기록
*/

// https://source-sc.tistory.com/53

#if 1
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 1001
struct Pos { int x, y; };
using namespace std;
int N, W;
int dp[MAX][MAX], order[MAX][MAX];
Pos events[MAX];
int dist(Pos a, Pos b) { return abs(a.x - b.x) + abs(a.y - b.y); }
int dfs(int p1, int p2)
{
	if (p1 == W || p2 == W) return 0;
	int& ret = dp[p1][p2];
	if (ret != -1) return ret;
	int next = max(p1, p2) + 1;
	Pos p1Pos = p1 == 0 ? Pos{ 1,1 } : events[p1];
	Pos p2Pos = p2 == 0 ? Pos{ N,N } : events[p2];
	int dist1 = dist(p1Pos, events[next]) + dfs(next, p2);
	int dist2 = dist(p2Pos, events[next]) + dfs(p1, next);
	if (dist1 < dist2) order[p1][p2] = 1;
	else order[p1][p2] = 2;
	return ret = min(dist1, dist2);
}
	
void printOrder()
{
	int p1 = 0, p2 = 0;
	for (int i = 1; i <= W; i++)
	{
		if (order[p1][p2] == 1) { cout << 1 << '\n'; p1 = i; }
		else { cout << 2 << '\n'; p2 = i; }
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> W;
	for (int i = 1; i <= W; i++) { cin >> events[i].x >> events[i].y; }
	cout << dfs(0, 0) << "\n";
	printOrder();
}

#if 0
// follows the path that the dfs function took. 
void reconstruct(int p1, int p2) {
	if (p1 == W || p2 == W) return;
	int next = max(p1, p2) + 1;
	Pos p1Pos = p1 == 0 ? Pos{ 1,1 } : events[p1];
	Pos p2Pos = p2 == 0 ? Pos{ N,N } : events[p2];
	int dist1 = dist(p1Pos, events[next]) + (dp[next][p2] != -1 ? dp[next][p2] : dfs(next, p2));
	int dist2 = dist(p2Pos, events[next]) + (dp[p1][next] != -1 ? dp[p1][next] : dfs(p1, next));

	if (dist1 < dist2) {
		// choose p1
		cout << 1 << "\n";
		reconstruct(next, p2);
	}
	else {
		// choose p2
		cout << 2 << "\n";
		reconstruct(p1, next);
	}
}
#endif
#endif