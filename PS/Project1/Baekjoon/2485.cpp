#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * b / gcd(a, b); }
int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false); 
	int n; cin >> n; vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	int m = v[1] - v[0]; int count = 0; int index = 0;
	for (int i = 2; i < n; i++) m = gcd(m, v[i] - v[i - 1]);
	for (int pos = v[0]; pos <= v[n - 1]; pos += m)
	{
		if (pos < v[index]) count++;
		else if (pos == v[index]) index++;
	}
	cout << count;
}