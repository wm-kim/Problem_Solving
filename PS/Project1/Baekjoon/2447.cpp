#include <iostream>
#include <cmath>
using namespace std;

void solve(int** a, int x, int y, int n)
{
	if (n == 1) return;
	
	for (int i = x + n / 3; i < x + n / 3 * 2; i++)
		for (int j = y + n / 3; j < y + n / 3 * 2; j++)
			a[i][j] = 0;
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == 1 && j == 1) continue;
			solve(a, x + i * n / 3, y + j * n / 3, n / 3);
		}
	}
}

int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	int n; cin >> n;
	
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
		for (int j = 0; j < n; j++)
			a[i][j] = 1;
	}
	
	solve(a, 0, 0, n);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 1) cout << "*";
			else cout << " ";
		}
		cout << "\n";
	}
}
