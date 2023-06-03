#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define MAX 1000000
int N;
int color[1001][3];
int dp[1001][3];
int ans = MAX;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> color[i][0] >> color[i][1] >> color[i][2];
	for (int RGB = 0; RGB <= 2; RGB++) 
	{
		for (int i = 0; i <= 2; i++)
		{
			if (i == RGB) dp[1][i] = color[1][i];
			else dp[1][i] = MAX;
		}
		for (int i = 2; i <= N; i++)
		{
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + color[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + color[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + color[i][2];
		}
		for (int i = 0; i <= 2; i++)
		{
			if (i == RGB) continue;
			else ans = min(ans, dp[N][i]);
		}
	}
	cout << ans;
}

// RGB : 1번 집의 색
// 1번집에 지정된 색 이외의 색은 MAX로 지정하여 dp할때 선택되지 않도록 함
// 1번집 색과 N번집 색이 겹치지 않게 함