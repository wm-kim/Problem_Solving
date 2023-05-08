#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int n; cin >> n; vector<int> v(n); vector<int> u(n);
	for (int i = 0; i < n; i++) { cin >> v[i]; u[i] = v[i]; }
	sort(u.begin(), u.end());
	u.erase(unique(u.begin(), u.end()), u.end());
	for (int i = 0; i < n; i++) cout << lower_bound(u.begin(), u.end(), v[i]) - u.begin() << ' ';
}