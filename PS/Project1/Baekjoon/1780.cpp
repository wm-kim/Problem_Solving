#include <iostream>
#include <vector>
using namespace std;
int cnt[3] = { 0, };
void solve(vector<vector<int>>& v, int x, int y, int size)
{
	if (size == 1) { cnt[v[y][x] + 1]++; return; }

	bool same = true;
	for (int i = y; i < y + size && same; i++) {
		for (int j = x; j < x + size; j++) {
			if (v[y][x] != v[i][j]) {
				same = false; break;
			}
		}
	}

	if (same) { cnt[v[y][x] + 1]++; return; }
	else
	{
		int n = size / 3;
		for (int i = 0; i < 3; i++) 
			for (int j = 0; j < 3; j++)
				solve(v, x + j * n, y + i * n, n);
	}
}
	
int main()
{
	int n; cin >> n; vector<vector<int>> v(n, vector<int>(n));
    for (int y = 0; y < n; ++y) for (int x = 0; x < n; ++x) cin >> v[y][x];
    solve(v, 0, 0, n);
	for (int i = 0; i < 3; ++i) cout << cnt[i] << '\n';
}