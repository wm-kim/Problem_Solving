#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000001;
int dp[MAX], pre[MAX];
int main() {
    int N; cin >> N;
    dp[1] = 0;
    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + 1;
        pre[i] = i - 1;
        if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
            dp[i] = dp[i / 2] + 1;
            pre[i] = i / 2;
        }
        if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
            dp[i] = dp[i / 3] + 1;
            pre[i] = i / 3;
        }
    }
    cout << dp[N] << '\n';
    vector<int> ans;
    for (int i = N; i != 0; i = pre[i]) {
        ans.push_back(i);
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
}

// prev 없이 풀기 : 
// 경로를 추적하는 것은 역으로 돌면서 각 연산을 진행했을 때와 
// 현재 값과 1 차이(하나의 연산)가 차이가 나면 그 숫자로 가면 된다.

/*
    while (n != 0) {
        cout << n << " ";
        if (dp[n] == dp[n - 1] + 1) {
            n = n - 1;
        }
        else if (n%2 == 0 && dp[n] == dp[n / 2] + 1) {
            n = n / 2;
        }
        else if (n%3 == 0 && dp[n] == dp[n / 3] + 1) {
            n = n / 3;
        }
    }
*/