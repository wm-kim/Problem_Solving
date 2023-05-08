#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	int n; cin >> n; set<int> s;
	for (int i = 0; i < n; i++) {
		int x; cin >> x; s.insert(x);
	}
	int m; cin >> m; vector<int> v(m);
	for (int i = 0; i < m; i++) cin >> v[i];
	for (int i = 0; i < m; i++) {
		cout << (s.find(v[i]) != s.end() ? 1 : 0) << ' ';
	}
}