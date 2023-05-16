#include <iostream>
#include <algorithm>	
#include <vector>
using namespace std;
int main()
{
	int n; cin >> n; 
	vector<int> v(n + 1); for (int i = 1; i <= n; ++i) cin >> v[i];
	sort(v.begin(), v.end());
	vector<int> presum(n + 1);
	for (int i = 1; i <= n; ++i) presum[i] = presum[i - 1] + v[i];
	int ans = 0; for (int i = 1; i <= n; ++i) ans += presum[i];
	cout << ans << "\n";
}