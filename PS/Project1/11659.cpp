#include <iostream>
using namespace std;
int presum[100001];
int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	int n, m; cin >> n >> m; 
	for (int i = 1; i <= n; i++)
	{
		int num; cin >> num; presum[i] = presum[i - 1] + num;
	}
	while (m--)
	{
		int i, j; cin >> i >> j;
		cout << presum[j] - presum[i - 1] << "\n";
	}
}