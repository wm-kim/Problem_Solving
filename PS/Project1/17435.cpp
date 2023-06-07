#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int m, Q, n, x;
int st[19][200001]; // log2(500,000) 18.xxx -> 19
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> m;
	for (int i = 1; i <= m; i++) cin >> st[0][i];
	for (int i = 1; i < 19; i++)
		for (int j = 1; j <= m; j++)
			st[i][j] = st[i - 1][st[i - 1][j]];
	cin >> Q;
	while (Q--)
	{
		cin >> n >> x; // compute f^n(x)
		// 2진수로 변환, n이 0이 될 때까지
		for (int i = 0; n; i++, n >>= 1) 
			if (n & 1) x = st[i][x];
		// n & 1 = LSB of n
		cout << x << "\n";
	}
}