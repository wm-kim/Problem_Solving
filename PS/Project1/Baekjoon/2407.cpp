#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string dp[101][101];
string bigNumAdd(string num1, string num2) {
    long long sum = 0;
    string result;
    while (!num1.empty() || !num2.empty() || sum) {
        if (!num1.empty()) {
            sum += num1.back() - '0';
            num1.pop_back();
        }
        if (!num2.empty()) {
            sum += num2.back() - '0';
            num2.pop_back();
        }
        result.push_back((sum % 10) + '0');
        sum /= 10;
    }
    // 더한 결과가 역순이므로 뒤집어준다.
    reverse(result.begin(), result.end());
    return result;
}

string combination(int n, int r) {
    if (dp[n][r] != "") return dp[n][r];
    if (n == r || r == 0) return "1";
    return dp[n][r] = bigNumAdd(combination(n - 1, r - 1), combination(n - 1, r));
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    cout << combination(n, m);
}