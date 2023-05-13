#include <iostream>
#include <algorithm>
using namespace std;
int m[501][501];
int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> m[i][j];
			if (j == 0) m[i][j] = m[i - 1][j] + m[i][j];
			else if (j == i) m[i][j] = m[i - 1][j - 1] + m[i][j];
			else m[i][j] = max(m[i - 1][j - 1], m[i - 1][j]) + m[i][j];
		}
	}
	int max_sum = 0;
	for (int i = 0; i < n; i++) max_sum = max(max_sum, m[n - 1][i]);
	cout << max_sum;
}