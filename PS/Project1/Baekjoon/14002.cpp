#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dp[1000], N, pre[1000];
int main()
{
	cin >> N;
	vector<int> v(N); for (int i = 0; i < N; i++) cin >> v[i];
	fill(pre, pre + N, -1);
	for (int i = 0; i < N; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++) 
			if (v[i] > v[j])
			{
				if (dp[i] < dp[j] + 1)
				{
					dp[i] = dp[j] + 1;
					pre[i] = j;
				}
			}
	}
	cout << *max_element(dp, dp + N) << "\n";
	vector<int> ans;
	
	for (int i = max_element(dp, dp + N) - dp; i >= 0; i = pre[i]) ans.push_back(v[i]);
	for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
}

// O(N^2) LIS를 출력하는 문제