#include <iostream>
using namespace std;
int main()
{
	int n; cin >> n; int c = 1; int sum = 0;
	while (n > sum)
	{
		sum += c; c++;
	}
	int x, y = 0;
	if ((c - 1) % 2 == 0)
	{
		x = n - (sum - c + 1);
		y = c - x;
	}
	else if ((c - 1) % 2 == 1)
	{
		y = n - (sum - c + 1);
		x = c - y;
	}
	cout << x << "/" << y << endl;
}
