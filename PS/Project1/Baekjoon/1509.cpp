#include <iostream>
#include <vector>
#define MAX 2500
using namespace std;
string s; bool isPal[MAX][MAX]; int dp[MAX];
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> s;
	for (int i = 0; i < s.size(); i++) isPal[i][i] = true;
	for (int i = 0; i < s.size() - 1; i++) if (s[i] == s[i + 1]) isPal[i][i + 1] = true;
	for (int i = 2; i < s.size(); i++)
		for (int j = 0; j < s.size() - i; j++)
			if (s[j] == s[j + i] && isPal[j + 1][j + i - 1]) isPal[j][j + i] = true;
	dp[0] = 1; 
	for (int i = 1; i < s.size(); i++)
	{
		dp[i] = dp[i - 1] + 1;
		for (int j = 0; j < i; j++)
			if (isPal[j][i])
			{
				if (j == 0) dp[i] = 1;
				else dp[i] = min(dp[i], dp[j - 1] + 1);
			}
	}
	cout << dp[s.size() - 1];
}

// dp[i] = 0 ~ i까지의 팰린드롬 분할의 최소 개수