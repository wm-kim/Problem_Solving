#include <iostream>
#include <vector>
using namespace std;
vector<int> dp[26];
int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false); int count[26] = { 0, };
	string s; int n; cin >> s >> n;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 0; j < 26; j++)
			if (s[i] == 'a' + j) dp[j].push_back(++count[j]);
			else dp[j].push_back(count[j]);
	}
	while(n--)
	{
		char c; int l, r; cin >> c >> l >> r;
		int ans = (l > 0) ? dp[c - 'a'][r] - dp[c - 'a'][l - 1] : dp[c - 'a'][r];
		cout << ans << "\n";
	}
}