#include <iostream>
#include <vector>
using namespace std;
vector<bool> prime(1000001, true);
void eratosthenes()
{
	prime[0] = prime[1] = false;
	for (int i = 2; i <= 1000000; i++)
	{
		if (!prime[i]) continue;
		for (int j = 2 * i; j <= 1000000; j += i)
			prime[j] = false;
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	eratosthenes();
	int n; cin >> n; 
	while (n--)
	{
		int x; cin >> x; int count = 0;
		for (int a = 2; a <= x / 2; a++)
		{
			if (prime[a] && prime[x - a])
				count++;
		}
		cout << count << "\n";
	}
}