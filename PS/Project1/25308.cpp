#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
const int N = 8;
using namespace std;
vector<int> v(N), pm(N);
bool visited[N];
int ans;
bool check(double a1, double a2, double a3)
{
	if (a1 * a3 * sqrt(2) > a2 * (a1 + a3)) return false;
	else return true;
}
void permutation(int cnt)
{
	if (cnt == N)
	{
		bool isConvex = true;
		for (int i = 0; i < N; i++)
		{
			int a1 = pm[i];
			int a2 = pm[(i + 1) % N];
			int a3 = pm[(i + 2) % N];
			if (!check(a1, a2, a3))
			{
				isConvex = false;
				break;
			}
		}
		if (isConvex) ans++;
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			pm[cnt] = v[i];
			permutation(cnt + 1);
			visited[i] = false;
		}
	}
}

int main()
{
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	for (int i = 0; i < N; i++) cin >> v[i];
	permutation(0);
	cout << ans;
}