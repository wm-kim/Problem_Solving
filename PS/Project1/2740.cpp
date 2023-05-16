#include<iostream>
using namespace std;
int arr1[101][101];
int arr2[101][101];
int ans[101][101];
void mul(int n, int m, int k)
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= k; j++)
			for (int l = 1; l <= m; l++)
				ans[i][j] += arr1[i][l] * arr2[l][j];
}
int main()
{
	int n, m, k; cin >> n >> m;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> arr1[i][j];
	cin >> m >> k;
	for (int i = 1; i <= m; i++) for (int j = 1; j <= k; j++) cin >> arr2[i][j];
	mul(n, m, k);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++) cout << ans[i][j] << " ";
		cout << "\n";
	}
}