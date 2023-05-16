#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int64_t histogram(vector<int64_t>& v, int l, int r)
{
	if (l >= r) return v[l];
	int m = (l + r) / 2;
	int64_t maxArea = max(histogram(v, l, m), histogram(v, m + 1, r));
	int64_t minHeight = min(v[m], v[m+1]);
	int left = m; int right = m + 1;
	int64_t area = minHeight * 2;
	while (left > l || right < r)
	{
		if (right < r && (left == l || v[left - 1] < v[right + 1]))
		{
			right++;
			minHeight = min(minHeight, v[right]);
		}
		else
		{
			left--;
			minHeight = min(minHeight, v[left]);
		}
		area = max(area, minHeight * (right - left + 1));
	}
	return max(maxArea, area);
}
int main()
{
	while (true)
	{
		int n; cin >> n;
		if (n == 0) break;
		vector<int64_t> v(n); for (int i = 0; i < n; ++i) cin >> v[i];
		cout.precision(10);
		cout << fixed << histogram(v, 0, n - 1) << "\n";
	}
}