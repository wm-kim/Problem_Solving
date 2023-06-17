#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string LCS(string str1, string str2) {
    int m = str1.length();
    int n = str2.length(); 
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1; 
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int len = dp[m][n]; string lcs(len, ' '); 
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) { 
            lcs[len - 1] = str1[i - 1]; len--;
            i--; j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) i--;
        else j--; 
    }
    return lcs;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string str1, str2, ans;
    cin >> str1 >> str2;
    ans = LCS(str1, str2);
    cout << ans.length() << "\n";
    cout << ans << "\n";
}