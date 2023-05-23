#include <iostream>
typedef long long ll;
using namespace std;
ll binarySearch(ll N, ll k) {
	ll low = 1, high = N * N, mid, result = -1;
    while (low <= high) {
        ll mid = (low + high) / 2;
        ll count = 0;
        // i행은 i의 배수의 집합이므로 
        // mid를 i로 나눠주면 mid가 i행에서 몇 번째에 위치하는지 알 수 있다
		// cnt는 mid보다 작거나 같은 수의 개수
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