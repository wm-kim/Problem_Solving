#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> Matrix;

Matrix operator*(const Matrix& a, const Matrix& b) {
    Matrix res(2, vector<ll>(2, 0));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= MOD;
            }
        }
    }
    return res;
}

Matrix pow(Matrix a, ll p) {
    Matrix res = { {1, 0}, {0, 1} };
    while (p > 0) {
        if (p & 1) res = res * a;
        a = a * a;
        p >>= 1;
    }
    return res;
}

ll fibonacci(ll n) {
    if (n <= 1) return n;
    Matrix mtx = { {1, 1}, {1, 0} };
    Matrix res = pow(mtx, n - 1);
    return res[0][0];
}

int main() {
    ll n; cin >> n;
    cout << fibonacci(n) << '\n';
    return 0;
}