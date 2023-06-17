// 냅색 알고리즘으로 푸는 문제
#include <iostream>
#include <vector>
using namespace std;
bool dp[31][40001] = { false };
int main()
{
	int n, m; cin >> n;
	vector<int> v(n + 1); for (int i = 1; i <= n; ++i) cin >> v[i];
	dp[0][0] = true; // 0개의 추로 0g을 만들 수 있다.
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j <= 40000; ++j)
		{
			if (dp[i - 1][j])
			{
				dp[i][j] = true;
				dp[i][j + v[i]] = true;
				dp[i][abs(j - v[i])] = true;
			}
		}
	}
	cin >> m;
	while (m--)
	{
		int w; cin >> w;
		if (w <= 40000 && dp[n][w]) cout << "Y ";
		else cout << "N ";
	}
}