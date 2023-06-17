#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;
int t;
int dp[501][501];
int sum[501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        for (int i = 1; i <= k; i++) {
            int a;
            cin >> a;
            sum[i] = sum[i - 1] + a; // 1~x 번째 파일까지의 크기 합
        }

        for (int i = 1; i < k; i++) { // i는 구해야하는 범위를 의미 -> ex. i=1이면 1~2번째 파일 등을 합칠 때를 의미
            for (int x = 1; x <= k - i; x++) { //x는 합치는 범위의 시작 부분을 의미 -> i가 범위를 의미하므로 k-i까지만 해주면 k까지 탐색하게 된다.
                int y = x + i;
                dp[x][y] = INT_MAX; // x~y 번째 파일들을 합치는데 필요한 최소 비용
                for (int mid = x; mid < y; mid++) { // mid는 구해야하는 범위를 두 부분으로 나누는 기준점을 의미
                    dp[x][y] = min(dp[x][y], dp[x][mid] + dp[mid + 1][y] + sum[y] - sum[x - 1]);
                    // dp[n][n]은 0이기 때문에 sum[y] - sum[x-1]로 dp[x][y]를 갱신 
                    // ex) dp[1][2] = dp[1][1] + dp[2][2] + sum[2] - sum[0]
                }
            }
        }
        cout << dp[1][k] << "\n";
    }
    return 0;
}