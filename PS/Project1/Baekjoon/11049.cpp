#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 2147483647
using namespace std;
int dp[501][501]; // dp[i][j] = i번째 행렬부터 j번째 행렬까지의 곱셈 연산 횟수의 최솟값
struct Matrix { int r, c; };
int main()
{
	int N; cin >> N;
	vector<Matrix> v(N + 1); for (int i = 1; i <= N; ++i) cin >> v[i].r >> v[i].c;
	for (int len = 1; len <= N; len++)
	{
		for (int i = 1; i <= N - len; i++)
		{
			int j = i + len;
			dp[i][i + len] = MAX; 
			for (int k = i; k < j; k++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + v[i].r * v[k].c * v[j].c);
		}
	}
	cout << dp[1][N] << "\n";
}
