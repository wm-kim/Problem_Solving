#include <iostream>
#include <vector>
using namespace std;
int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	int n, m; cin >> n >> m; 
	vector<int> v(n + 1, 0); for (int i = 1; i <= n; i++) cin >> v[i];
	int sumMax = 0; int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i <= m) { sum += v[i]; sumMax = sum; }
		else { sum += v[i] - v[i - m]; sumMax = max(sumMax, sum); }
	}
	cout << sumMax;
}