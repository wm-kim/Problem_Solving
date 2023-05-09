#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
	int n; cin >> n; int sum = 0; 
	vector<int> v(n); int count[8001] = { 0, };
	for (int i = 0; i < n; i++) 
	{ 
		int a; cin >> a; v[i] = a; sum += a;
		count[a + 4000]++;
	}
	
	cout << (int)round((double)sum / n) << endl;
	sort(v.begin(), v.end());
	cout << v[n / 2] << endl;
	
	vector<pair<int, int>> freq; 
	for (int i = 0; i < 8001; i++)
		if (count[i] != 0) freq.push_back(make_pair(i - 4000, count[i]));
	stable_sort(freq.begin(), freq.end(), [](pair<int, int> a, pair<int, int> b) {return a.second > b.second; });
	
	if (freq.size() > 1 && freq[0].second == freq[1].second) cout << freq[1].first << endl;
	else cout << freq[0].first << endl;
	cout << v[n - 1] - v[0] << endl;
}