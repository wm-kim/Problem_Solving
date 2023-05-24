#include <iostream>
#include <vector>
using namespace std;
vector<bool> prime(4000001, true);
void erathones(int n) {
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N; cin >> N;
    erathones(N);
    vector<int> primes;
    for (int i = 2; i <= N; i++) {
        if (prime[i]) { primes.push_back(i); }
    }
    int start = 0, end = 0, sum = 0, count = 0;
    while (true) {
        if (sum >= N) {
            sum -= primes[start++];
        }
        else if (end == primes.size()) {
            break;
        }
        else {
            sum += primes[end++];
        }
        if (sum == N) {
            count++;
        }
    }
    cout << count << "\n";
}