#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
int N, C; 
vector<ll> v(N);
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
	for (int i = 0; i < N; i++) cin >> v[i];
	vector<ll> group1, group2;
	dfs(0, N / 2, group1, 0);
	dfs(N / 2 + 1, N - 1, group2, 0);

	
}