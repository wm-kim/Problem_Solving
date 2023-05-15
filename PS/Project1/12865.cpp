#include <iostream>
using namespace std; 
int dp[101], v[101]; int dp[101][100001] = { 0 };
int main() {
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> dp[i] >> v[i];
		for (int j = 1; j <= k; j++) {
			if (j < dp[i]) dp[i][j] = dp[i - 1][j];
            // i��° ������ �賶�� ���Խ�ų �� �ִ� ��� 
            // dp[i-1][j] : i��° ������ �賶�� ���Խ�Ű�� ���� �ִ� ��ġ (�����ѵ� ���)
			// dp[i-1][j-w[i]] + v[i] : i��° ������ �賶�� ���Խ�Ų ���� �ִ� ��ġ (���Խ�Ų ���)
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - dp[i]] + v[i]);
		}
    }
    cout << dp[n][k];
}
