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
*/

// https://source-sc.tistory.com/53


