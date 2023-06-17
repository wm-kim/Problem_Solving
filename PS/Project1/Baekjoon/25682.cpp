#define VERSION 2

# if VERSION == 1
#include <iostream>
using namespace std;
int n, m, k, ans;
int w[2001][2001], b[2001][2001];
int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        string s; cin >> s;
        for (int j = 1; j <= m; ++j) {
            if ((i + j) % 2 == 0) {
                w[i][j] = w[i - 1][j] + w[i][j - 1] - w[i - 1][j - 1] + (s[j - 1] == 'B');
                b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + (s[j - 1] == 'W');
            }
            else {
                w[i][j] = w[i - 1][j] + w[i][j - 1] - w[i - 1][j - 1] + (s[j - 1] == 'W');
                b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + (s[j - 1] == 'B');
            }
        }
    }
    ans = k * k;
    for (int i = 1; i <= n - k + 1; ++i) {
        for (int j = 1; j <= m - k + 1; ++j) {
            ans = min(ans, w[i + k - 1][j + k - 1] - w[i - 1][j + k - 1] - w[i + k - 1][j - 1] + w[i - 1][j - 1]);
            ans = min(ans, b[i + k - 1][j + k - 1] - b[i - 1][j + k - 1] - b[i + k - 1][j - 1] + b[i - 1][j - 1]);
        }
    }
    cout << ans << "\n";
}
#endif
