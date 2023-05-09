#include <iostream>
using namespace std;

uint64_t comb1(int n, int r) {
    if (n < r) return 0;
    uint64_t result = 1;
	for (int i = 1; i <= r; i++)
	{
		result *= (uint64_t)n - i + 1;
		result /= i;
	}
	return result;
}

/*
// slow
uint64_t comb2(int n, int r) {
	if (n < r) return 0;
	else if (r == 0 || n == r) return 1;
	else return comb2(n - 1, r - 1) + comb2(n - 1, r);
}

// dynamic programming
uint64_t comb3(int n, int r) {
	if (n < r) return 0;
	// 2d array stack
	uint64_t** arr = new uint64_t * [n + 1];
	for (int i = 0; i <= n; i++)
		arr[i] = new uint64_t[r + 1];
	
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= r; j++)
		{
			if (j == 0 || i == j) arr[i][j] = 1;
			else if (i < j) arr[i][j] = 0;
			else arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
	
	return arr[n][r];
}
*/

int main() {
	int t; cin >> t;
	while (t--)
	{
		int r, n; cin >> r >> n;
        cout << comb1(n, r) << endl;
	}
}