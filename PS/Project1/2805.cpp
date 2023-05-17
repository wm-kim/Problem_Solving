#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
int main()
{
	int n, m; cin >> n >> m; ll mH = 0;
	vector<ll> v(n); for (int i = 0; i < n; i++) { cin >> v[i]; mH = max(mH, v[i]); }
	ll start = 0, end = mH, mid, ans = 0;
	while (start <= end)
	{
		mid = (start + end) / 2;
		ll tmp = 0;
		for (int i = 0; i < n; i++) if (v[i] > mid) tmp += v[i] - mid;
		if (tmp >= m) { ans = mid; start = mid + 1; }
		else end = mid - 1;
	}
	cout << ans << "\n";
}