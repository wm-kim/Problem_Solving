#include <iostream>
using namespace std;
int arr[1025][1025];
int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	int n, m; cin >> n >> m; 
	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= n; j++)
		{
			int num; cin >> num;
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + num;
		}
	}
	while (m--)
	{
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		cout << arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1] << "\n";
	}
}