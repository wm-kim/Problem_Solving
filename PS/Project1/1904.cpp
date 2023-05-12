#include <iostream>
using namespace std;
int m[1000001];

int tile(int n)
{
	if (n == 1 || n == 2) return m[n] = n;
	if (m[n] != 0) return m[n];
	return m[n] = (tile(n - 1) + tile(n - 2)) % 15746;
}

int main()
{
	int n; cin >> n; cout << tile(n);
}