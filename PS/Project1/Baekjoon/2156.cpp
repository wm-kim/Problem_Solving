#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n; cin >> n; vector<int> v(n + 1); vector<int> dp(n + 1);
	for (int i = 1; i <= n; i++) { cin >> v[i]; }
	dp[1] = v[1]; dp[2] = v[1] + v[2];
	for (int i = 3; i <= n; i++) 
	{
		// Case 1: i번째 포도주 잔을 마시지 않는 경우
		dp[i] = max(dp[i], dp[i - 1]);

		// Case 2: i번째 포도주 잔을 마시고, i-1번째 잔을 마시지 않는 경우
		dp[i] = max(dp[i], dp[i - 2] + v[i]);

		// Case 3: i번째 포도주 잔을 마시고, i-1번째 잔도 마시는 경우
		dp[i] = max(dp[i], dp[i - 3] + v[i - 1] + v[i]);
	}
	cout << dp[n];
}