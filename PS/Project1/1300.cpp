#include <iostream>
typedef long long ll;
using namespace std;
ll binarySearch(ll N, ll k) {
	ll low = 1, high = N * N, mid, result = -1;
    while (low <= high) {
        ll mid = (low + high) / 2;
        ll count = 0;
        for (ll i = 1; i <= N; i++) count += min(mid / i, N);
        if (count >= k) { result = mid; high = mid - 1; }
        else low = mid + 1;
    }
    return result;
}
int main() {
    cin.tie(NULL); cin.sync_with_stdio(false);
    ll n, k; cin >> n >> k;
	cout << binarySearch(n, k) << "\n";
}