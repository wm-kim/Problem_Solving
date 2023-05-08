#include <iostream>
using namespace std;
int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * b / gcd(a, b); }
int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b; cin >> a >> b;
		cout << lcm(a, b) << "\n";
	}
}