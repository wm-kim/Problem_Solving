#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000000000
typedef long long ll;
using namespace std;
int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	int n, c; cin >> n >> c;
	ll start = MAX, end, mid, ans;
	vector<ll> v(n); 
	for (int i = 0; i < n; ++i) cin >> v[i];
	sort(v.begin(), v.end());
	for (int i = 0; i < n - 1; ++i) start = min(start, v[i + 1] - v[i]);
	end = v[n - 1] - v[0];
	while (start <= end)
	{
		mid = (start + end) / 2;
		int cnt = 1; ll prev = v[0];
		for (int i = 1; i < n; ++i)
			if (v[i] - prev >= mid) { cnt++; prev = v[i]; }
		if (cnt >= c) { ans = mid; start = mid + 1; }
		else end = mid - 1;
	}
	cout << ans << '\n';
}