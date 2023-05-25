#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
int N, C; 
vector<ll> v;
void dfs(int start, int end, vector<ll>& group, ll sum)
{
	if (start > end)
	{
		group.push_back(sum);
		return;
	}
	else
	{
		dfs(start + 1, end, group, sum);
		dfs(start + 1, end, group, sum + v[start]);
	}
}

int main()
{
	cin >> N >> C;
	v.resize(N, 0);
	for (int i = 0; i < N; i++) cin >> v[i];
	vector<ll> group1, group2;
	dfs(0, N / 2, group1, 0);
	dfs(N / 2 + 1, N - 1, group2, 0);
	sort(group2.begin(), group2.end());
	int ans = 0;
	for (int i = 0; i < group1.size(); i++)
	{
		ans += upper_bound(group2.begin(), group2.end(), C - group1[i]) - group2.begin();
	}
	cout << ans;
}