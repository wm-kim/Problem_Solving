#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> Matrix;
#define MOD 1000
// can use operator function
Matrix mul(const Matrix& a, const Matrix& b)
{
	int n = a.size();
	Matrix res(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) 
				res[i][j] += (a[i][k] * b[k][j]);
			res[i][j] %= MOD;
		}
	}
	return res;
}
Matrix pow(Matrix&v, ll b)
{
	if (b == 1) return v;
	int n = v.size();
	auto tmp = pow(v, b / 2);
	if (b % 2 == 0) return mul(tmp, tmp);
	else return mul(mul(tmp, tmp), v);
}
int main()
{
	cin.tie(NULL); ios::sync_with_stdio(false);
	ll n, b; cin >> n >> b;
	Matrix v(n, vector<int>(n));
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> v[i][j];
	auto ans = pow(v, b);
	for (int i = 0; i < n; i++) { for (int j = 0; j < n; j++) cout << ans[i][j] % MOD << " "; cout << "\n"; }
}