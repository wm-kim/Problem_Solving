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
	// Initialize the number of paths from current position
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
�־��� �ڵ忡�� dp[x][y]�� ���� ��ġ (x, y)���� ���������� �� �� �ִ� ����� ���� �����ϴ� �����Դϴ�. 
���� dp[x][y]�� 0���� �ʱ�ȭ�ϴ� ������ ���� ��ġ���� �����Ͽ� ���������� �����ϴ� ����� ���� ����ϱ� ���ؼ��Դϴ�.

dp[x][y]�� 0���� �ʱ�ȭ�ϴ� ������ ������ �����ϴ�:

dp[x][y]�� ������ �湮�� ��� ���� ����� �� �����Ƿ�, 
���� ��ġ (x, y)���� ���ο� ��θ� Ž���ϱ� ���� ���� ���� �ʱ�ȭ�ؾ� �մϴ�.
�ʱ�ȭ���� ������ ������ ���� ��� ���� ���ο� ��� ���� �����Ǿ� �߸��� ����� ���� �� �ֽ��ϴ�.
�Ź� dp[x][y]�� ����ϱ� ���� �ʱ�ȭ�ϸ�, 
�� ��ġ (x, y)���� ������������ ��� ���� ��Ȯ�ϰ� ����� �� �ֽ��ϴ�.
���� dp[x][y] = 0; ������ �� ��ġ���� �����Ͽ� ���������� �����ϴ� ����� ���� 
��Ȯ�ϰ� ����ϱ� ���� dp[x][y] ���� �ʱ�ȭ�ϴ� ������ �մϴ�.
*/