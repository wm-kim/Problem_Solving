#if 0
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
const int MAX_N = 1000;
using namespace std;
const int MOD = 1000000003;
int N, K;
int dp[MAX_N / 2][MAX_N];

int dfs(int depth, int last)
{
	if (depth == K) return 1;
	else if (last == N) return 0;
	
	if (dp[depth][last] != -1) return dp[depth][last];
	dp[depth][last] = 0;
	for (int i = last + 2; i <= N; i++)
	{
		dp[depth][last] += dfs(depth + 1, i);
		dp[depth][last] %= MOD;
	}

	return dp[depth][last];
}

int main()
{
	cin >> N >> K;
	if (K > N / 2) cout << "0\n";
	else
	{
		for (int i = 0; i < MAX_N / 2; i++)
			for (int j = 0; j < MAX_N; j++)
				dp[i][j] = -1;
		int ans = 0;
		for (int i = 1; i <= N; i++)
		{
			ans += dfs(1, i);
			ans %= MOD;
		}
		cout << ans << "\n";
	}
}
#endif

// dp[j][i] : j색상환에서 i개의 색을 선택하는 경우의 수
// dp[N][K]를 구해야하므로 
// (1) N번째 색을 선택하지 않는 경우
// 1~N-1 까지의 색중에서 K개의 색을 고르는 경우의 수 = dp[N - 1][K]
// (2) N번째 색을 선택하는 경우
// 2~N-2 까지의 색중에서 K-1개의 색을 고르는 경우의 수 = dp[N-3][K-1]

// 1. idx 색을 선택: dp[idx-2][k-1] 
// 2. idx 색을 선택하지 않음 : dp[idx-1][k]
// dp[idx][k] = dp[idx-2][k-1] + dp[idx-1][k]

#include <iostream>
#define MOD 1000000003
using namespace std;
int N, K;
int dp[1001][1001];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		dp[i][0] = 1;
		dp[i][1] = i;
	}
	for (int i = 2; i <= N; ++i)
		for (int j = 2; j <= K; ++j)
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
	cout << (dp[N - 1][K] + dp[N - 3][K - 1]) % MOD << '\n';
}