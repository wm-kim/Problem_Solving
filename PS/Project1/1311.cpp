#if 0
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int N, cost[21][21], dp[1 << 20];
int bitMask = 0;
int countBits(int n)
{
	int cnt = 0;
	while (n) { if (n & 1) ++cnt; n = n >> 1; }
	return cnt;
}
void solve(int N)
{
	fill(dp, dp + (1 << N), 10000);
	for (int i = 0; i < N; i++)
		for (int j = 1; j <= N; j++)
		{
			if (dp[1 << i] > cost[i][j])
			{
				dp[1 << i] = cost[i][j];
				bitMask |= (1 << i);
			}
		}

	for (int i = 1; i < (1 << N); i++)
	{
		for (int j = 0; j < countBits(i); j++)
		{
			int minCost = 10000;
			for (int k = 0; k < N; k++)
				// find unoccupied bit
				if (!(bitMask & (1 << k)))
					minCost = min(minCost, cost[j + 1][k + 1]);
			dp[i] = min(dp[i], dp[i - (1 << j)] + minCost);
		}
	}
	cout << dp[(1 << N) - 1];
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> cost[i][j];

	solve(N);
}
#endif

// N : 1~20
// cost[i][j] i사람이 j번일을 하는데 드는 비용
// mask는 i번째 비트를 통해 i번째 작업이 할당되었는지 알려주는 것

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int N, cost[21][21], dp[1 << 20];
int countBits(int n)
{
	int cnt = 0;
	while (n) { if (n & 1) ++cnt; n >>= 1; }
	return cnt;
}
int solve()
{
	for (int i = 1; i <= (1 << N); i++) dp[i] = 1e9;
	dp[0] = 0; // 
	for (int i = 0; i < (1 << N); i++)
	{
		int x = countBits(i);
		for (int j = 0; j < N; j++)
		{
			if (!(i & (1 << j))) // j번째 일을 아직 안했으면
				dp[i | (1 << j)] = min(dp[i | (1 << j)], dp[i] + cost[x + 1][j + 1]);
		}
	}
	return dp[(1 << N) - 1];
}
int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> cost[i][j];
	cout << solve();
}