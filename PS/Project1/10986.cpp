#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long ll;
int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	ll n, m; cin >> n >> m;
	unordered_map<ll, ll> modFreq;
	ll prefixSum = 0; ll count = 0;
	for (int i = 1; i <= n; i++)
	{
		ll number; cin >> number;
		prefixSum += number;
		modFreq[prefixSum % m]++;
	}
	for (auto& [key, value] : modFreq)
	{
		if (key == 0) count += value;
		count += value * (value - 1) / 2;
	}
	cout << fixed << count;
}