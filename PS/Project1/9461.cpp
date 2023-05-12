#include <iostream>
#include <vector>
using namespace std;
long long m[101];

long long P(int n) {
    if (n <= 3)  return m[n] = 1;
    if (m[n] != 0) return m[n];
    return m[n] = P(n - 2) + P(n - 3);
}

int main() {
    int T;
    cin >> T;
    while (T--)
    {
        int N; cin >> N; cout << P(N) << "\n";
    }
}