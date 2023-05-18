#include <iostream>
#include <vector>
using namespace std;
struct App { int mem, cost; };
/*
* 
* 발상의 전환이 필요한 냅색 문제
* 
문제에서 각 앱의 비활성화 비용은 0 이상 100 이하의 정수이므로,
최대 비용은 앱의 개수(최대 100개)와 각 앱의 최대 비용(100)을 곱한 값, 즉 10000
*/
int dp[101][10001];
int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	int n, m; cin >> n >> m;
	vector<App> apps(n + 1); 
	for (int i = 1; i <= n; i++) cin >> apps[i].mem;
	for (int i = 1; i <= n; i++) cin >> apps[i].cost;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 10000; j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j >= apps[i].cost)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - apps[i].cost] + apps[i].mem);
		}
	}

	for (int i = 0; i <= 10000; i++)
		if (dp[n][i] >= m) { cout << i << "\n"; break; }
}