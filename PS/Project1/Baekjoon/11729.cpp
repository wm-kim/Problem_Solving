#include <iostream>
using namespace std;
void hanoi(int n, int from, int by, int to)
{
	if (n == 1)
	{
		cout << from << " " << to << '\n';
	}
	else
	{
		hanoi(n - 1, from, to, by);
		cout << from << " " << to << '\n';
		hanoi(n - 1, by, from, to);
	}
}
int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	int n; cin >> n; cout << (1 << n) - 1 << '\n'; hanoi(n, 1, 2, 3);
}