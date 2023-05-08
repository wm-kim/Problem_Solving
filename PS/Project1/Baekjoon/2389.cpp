#include <iostream>
using namespace std;
int main() {
	// greedy
	//int N;
	//cin >> N;
	//int ans = 0;
	//while (N >= 0) {
	//	if (N % 5 == 0) {	
	//		ans += (N / 5);	
	//		cout << ans << endl;
	//		return 0;
	//	}
	//	N -= 3;	//3kg�� ���� 
	//	ans++;	//���� �ϳ� �þ
	//}
	//cout << -1 << endl;

	// DP dp[i] = min(dp[i-3] + 1, dp[i-5] +1)
	int dp[5001] = { 0, };
	int n;
	cin >> n;
	//3kg�� 5kg�� ����� ���� �ּ��� �������� 1
	//���� dp[3]�� dp[5]�� ������ 1
	dp[3] = dp[5] = 1;
	
	//3�� 5 ������ 6���� for loop ��ȸ
	for (int i = 6; i <= n; i++) {
		if (dp[i - 3]) dp[i] = dp[i - 3] + 1;

		//�̹� dp[i-3]�� ���� �����Ҷ� dp[i]�� ������Ʈ �ƾ��� �� �ִ�.
		//���� dp[i]�� ���� ���ٸ� dp[i] = dp[i-5] +1 �� ������Ʈ
		if (dp[i - 5]) dp[i] = dp[i] ? min(dp[i], dp[i - 5] + 1) : dp[i - 5] + 1;
	}
	cout << (dp[n] == 0 ? -1 : dp[n]) << endl;
	return 0;
}