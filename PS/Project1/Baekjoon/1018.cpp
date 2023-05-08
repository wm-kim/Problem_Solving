#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, m; cin >> n >> m;
	vector<vector<char>> a(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	
	int ans = 100;
	for (int i = 0; i <= n - 8; i++)
	{
		for (int j = 0; j <= m - 8; j++)
		{
			int cnt1 = 0;
			int cnt2 = 0;
			for (int k = i; k < i + 8; k++) {
				for (int l = j; l < j + 8; l++) {
					if ((k + l) % 2 == 0) {
						if (a[k][l] != 'W') cnt1++;
						if (a[k][l] != 'B') cnt2++;
					}
					else {
						if (a[k][l] != 'B') cnt1++;
						if (a[k][l] != 'W') cnt2++;
					}
				}
			}
			ans = min(ans, cnt1);
			ans = min(ans, cnt2);
		}
	}
	cout << ans << '\n';
}