#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
typedef long long ll;
using namespace std;
bool is_prime(ll x)
{
	if (x == 0 || x == 1) return false;
	for (ll i = 2; i <= sqrt(x); i++)
		if (x % i == 0)
			return false;
	return true;
}
int main()
{
	int N, left = 2, right = 2, sum = 2, cnt = 0;
	cin >> N;
	for (left = 2; left <= N; left++)
	{
		while (sum <= N)
		{
			cout << left << " " << right << " " << sum << "\n";
			if (sum == N) {
				cnt++; 
				if (is_prime(left)) sum -= left;
			}
			right++;
			if (right > N) break;
			else if (is_prime(right)) sum += right;
		}
		if (is_prime(left)) sum -= left;
		cout << left << " " << right << " " << sum << "\n";
	}
	cout << cnt;
}