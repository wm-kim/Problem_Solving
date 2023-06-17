#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#define MAX_N 15
#define MAX_K 100
using namespace std;
typedef long long ll;
int N, K, modsOf1eN[51], modsOfNum[15];
ll dp[1 << MAX_N][MAX_K];
vector<string> s(MAX_N);
int mod(string n, int k)
{
	int r = 0;
	for (int i = 0; i < n.size(); i++)
	{
		r = r * 10 + (n[i] - '0'); r %= k;
	}
	return r;
}
ll gcd(ll a, ll b) { if (b > a) swap(a, b); return b ? gcd(b, a % b) : a; }
void solve()
{
	for (int visited = 0; visited < (1 << N); visited++)
	{
		for (int i = 0; i < N; i++)
		{
			if (visited & (1 << i)) continue;
			for (int j = 0; j < K; j++) 
			{
				int next = (j * modsOf1eN[s[i].size()] + modsOfNum[i]) % K;
				dp[visited | (1 << i)][next] += dp[visited][j];
			}
		}
	}
}
int main()
{
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> s[i];
	cin >> K;
	dp[0][0] = 1;
	modsOf1eN[0] = 1 % K; 
	for (int i = 1; i <= 50; i++) modsOf1eN[i] = (modsOf1eN[i - 1] * 10) % K;
	for (int i = 0; i < N; i++) modsOfNum[i] = mod(s[i], K);
	solve();
	ll p = dp[(1 << N) - 1][0], q = 1;
	for (int i = 1; i <= N; i++) q *= i;
	ll g = gcd(p, q);
	cout << p / g << '/' << q / g;
}

// modsOf1eN는 10의 거듭제곱들의 나머지 수들을 미리 저장해놓은 것
// j는 현재 나머지
// dp[visited][j] : visited값을 뽑아 만든 순열 중 나머지가 j인 것의 개수