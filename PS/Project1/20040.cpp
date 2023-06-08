#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, m, a, b;
int st[500001], rnk[500001];
int find(int x)
{
	if (st[x] == x) return x;
	else return st[x] = find(st[x]);
}
void merge(int x, int y)
{
	x = find(x); y = find(y);
	if (x == y) return;
	if (rnk[x] > rnk[y]) st[y] = x;
	else {
		st[x] = y;
		if (rnk[x] == rnk[y]) rnk[y]++;
	}
}
int main()
{
	cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> m;
	for (int i = 0; i < N; i++) st[i] = i;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		if (find(a) == find(b)) {
			cout << i;
			return 0;
		}
		else merge(a, b);
	}
	cout << 0;
}