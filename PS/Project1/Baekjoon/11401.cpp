#include<iostream>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll fact(int s, int n)
{
    ll tmp = 1;
    for (int i = s; i <= n; i++) tmp = tmp * i % MOD;
    return tmp;
}
ll power(int a, int b)
{
    if (b == 1) return a % MOD;
    ll tmp = power(a, b / 2);
	if (b % 2) return tmp * tmp % MOD * a % MOD;
	else return tmp * tmp % MOD;
}
int main(void)
{
    int n, k; cin >> n >> k;
    cout << fact(n - k + 1, n) * power(fact(1, k), MOD - 2) % MOD;
}