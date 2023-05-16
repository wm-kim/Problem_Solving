#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef	long long ll;
ll ans;
int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	int n; cin >> n; 
	vector<ll> dist(n); for (int i = 1; i < n; ++i) cin >> dist[i];
	vector<ll> cost(n + 1); vector<ll> minCost(n + 1, 1e9);
	for (int i = 1; i <= n; i++) { cin >> cost[i]; minCost[i] = min(minCost[i - 1], cost[i]); }
	for (int i = 1; i < n; i++) ans += dist[i] * minCost[i];
	cout << fixed << ans;
}

/*  don't necessarily need to store the minCost values in a vector. 
Instead, you can keep track of the minimum cost encountered so far using a single variable. */