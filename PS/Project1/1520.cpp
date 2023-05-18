#if 0
#include <iostream>
#include <algorithm>
#define MAX 2147483647
using namespace std;
int road[501][501], dp[501][501];
int main()
{
	int M, N; cin >> M >> N;
	for (int i = 1; i <= M; i++) for (int j = 1; j <= N; j++) cin >> road[i][j];
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == 1 && j == 1) dp[i][j] = 1;
			if (i > 1 && road[i][j] < road[i - 1][j]) dp[i][j] += dp[i - 1][j];
			if (j > 1 && road[i][j] < road[i][j - 1]) dp[i][j] += dp[i][j - 1];
		}
	}
	for (int i = M; i >= 1; i--)
	{
		for (int j = N; j >= 1; j--)
		{
			if (i == M && j == N) continue;
			if (i < M && road[i][j] < road[i + 1][j]) dp[i][j] += dp[i + 1][j];
			if (j < N && road[i][j] < road[i][j + 1]) dp[i][j] += dp[i][j + 1];
		}
	}
	
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++) cout << dp[i][j] << " ";
		cout << "\n";
	}
}
#endif

// dfs + dp
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
int M, N;
int heights[501][501];
ll dp[501][501];
bool visited[501][501] = { false };
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
ll dfs(int x, int y) {
	// Reached the destination
	if (x == M && y == N) return 1;
	// Return the already calculated value
	if (visited[x][y]) return dp[x][y];  

	visited[x][y] = true;
	// **Initialize the number of paths from current position**
	dp[x][y] = 0; 

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 1 && nx <= M && ny >= 1 && ny <= N && heights[nx][ny] < heights[x][y]) 
			dp[x][y] += dfs(nx, ny);
	}
	return dp[x][y];
}

int main() {
	cin >> M >> N;
	for (int i = 1; i <= M; i++) 
		for (int j = 1; j <= N; j++)
			cin >> heights[i][j];
	cout << dfs(1, 1) << "\n";
}

/*
주어진 코드에서 dp[x][y]는 현재 위치 (x, y)에서 목적지까지 갈 수 있는 경로의 수를 저장하는 변수입니다. 
따라서 dp[x][y]를 0으로 초기화하는 이유는 현재 위치에서 시작하여 목적지까지 도달하는 경로의 수를 계산하기 위해서입니다.

dp[x][y]를 0으로 초기화하는 이유는 다음과 같습니다:

dp[x][y]에 이전에 방문한 경로 수가 저장될 수 있으므로, 
현재 위치 (x, y)에서 새로운 경로를 탐색하기 전에 이전 값을 초기화해야 합니다.
초기화하지 않으면 이전에 계산된 경로 수와 새로운 경로 수가 누적되어 잘못된 결과가 나올 수 있습니다.
매번 dp[x][y]를 계산하기 전에 초기화하면, 
각 위치 (x, y)에서 목적지까지의 경로 수를 정확하게 계산할 수 있습니다.
따라서 dp[x][y] = 0; 문장은 각 위치에서 시작하여 목적지까지 도달하는 경로의 수를 
정확하게 계산하기 위해 dp[x][y] 값을 초기화하는 역할을 합니다.
*/