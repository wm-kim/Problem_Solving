#include <iostream>
#include <vector>
using namespace std;
int main()
{
	// 각 위치에서의 LIS 길이를 저장하는 배열
	int n; cin >> n; vector<int> v(n + 1); vector<int> dp(n+1, 1);
	for (int i = 1; i <= n; i++) { cin >> v[i]; }
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < i; j++)
			// 현재 요소 A[i]가 이전 요소 A[j]보다 크고,
			// A[j]를 끝점으로 하는 LIS 길이(dp[j])에 1을 더한 값(dp[j] + 1)이
			// A[i]를 끝점으로 하는 LIS 길이(dp[i])보다 큰 경우
			if (v[i] > v[j]) { dp[i] = max(dp[i], dp[j] + 1); } // LIS 길이를 갱신
	int ans = 0;
	for (int i = 1; i <= n; i++) { ans = ans > dp[i] ? ans : dp[i]; }
	cout << ans;
}