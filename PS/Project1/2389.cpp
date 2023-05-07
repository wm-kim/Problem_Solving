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
	//	N -= 3;	//3kg을 빼고 
	//	ans++;	//가방 하나 늘어남
	//}
	//cout << -1 << endl;

	// DP dp[i] = min(dp[i-3] + 1, dp[i-5] +1)
	int dp[5001] = { 0, };
	int n;
	cin >> n;
	//3kg와 5kg를 만드는 가장 최소의 봉지수는 1
	//따라서 dp[3]과 dp[5]는 무조건 1
	dp[3] = dp[5] = 1;
	
	//3과 5 다음인 6부터 for loop 순회
	for (int i = 6; i <= n; i++) {
		if (dp[i - 3]) dp[i] = dp[i - 3] + 1;

		//이미 dp[i-3]에 값이 존재할때 dp[i]가 업데이트 됐었을 수 있다.
		//만약 dp[i]에 값이 없다면 dp[i] = dp[i-5] +1 로 업데이트
		if (dp[i - 5]) dp[i] = dp[i] ? min(dp[i], dp[i - 5] + 1) : dp[i - 5] + 1;
	}
	cout << (dp[n] == 0 ? -1 : dp[n]) << endl;
	return 0;
}