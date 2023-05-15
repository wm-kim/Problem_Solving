#include <iostream>
using namespace std; 
int dp[101], v[101]; int dp[101][100001] = { 0 };
int main() {
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> dp[i] >> v[i];
		for (int j = 1; j <= k; j++) {
			if (j < dp[i]) dp[i][j] = dp[i - 1][j];
            // i번째 물건을 배낭에 포함시킬 수 있는 경우 
            // dp[i-1][j] : i번째 물건을 배낭에 포함시키기 전의 최대 가치 (포함한된 경우)
			// dp[i-1][j-w[i]] + v[i] : i번째 물건을 배낭에 포함시킨 후의 최대 가치 (포함시킨 경우)
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - dp[i]] + v[i]);
		}
    }
    cout << dp[n][k];
}
