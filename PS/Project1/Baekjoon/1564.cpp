#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
int main() {
    int K, N; cin >> K >> N;
    vector<int> v(K); int max = 0;
	for (int i = 0; i < K; i++) { cin >> v[i]; if (max < v[i]) max = v[i]; }
    ll start = 1, end = max, result = 0;
    while (start <= end) {
        ll mid = (start + end) / 2;
        int cnt = 0;
        for (int i = 0; i < K; i++) cnt += v[i] / mid;
        if (cnt >= N) {
            result = mid;
            start = mid + 1;
        }
        else end = mid - 1;
    }
    cout << result << "\n";
}