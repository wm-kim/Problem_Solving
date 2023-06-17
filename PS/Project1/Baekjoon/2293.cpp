#include <iostream>
#include <vector>
using namespace std;
int main() {
	cin.tie(NULL); cin.sync_with_stdio(false);
    int n, k; cin >> n >> k;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) std::cin >> coins[i];
    vector<int> dp(k + 1, 0);
    // 어떤 가치도 만들지 않는 경우(가치가 0인 경우)는 동전을 아예 사용하지 않는 한 가지 방법
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= k; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }
    cout << dp[k];
}

/*
동전을 하나씩 고려하면서, 그리고 각 동전에 대해 **오름차순**으로 가치를 계산하기 때문에
같은 구성의 동전들이 다른 순서로 나타나는 상황을 자연스럽게 제외하게 됩니다.
*/