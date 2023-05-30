#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, a, b;
int parent[500001], rnk[500001];
int find(int x)
{
	if (parent[x] == x) return x;
	else return parent[x] = find(parent[x]);
}
void merge(int x, int y)
{
	x = find(x); y = find(y);
	if (x == y) return;
	if (rnk[x] > rnk[y]) parent[y] = x;
	else {
		parent[x] = y;
		if (rnk[x] == rnk[y]) rnk[y]++;
	}
}
int main()
{
	cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) parent[i] = i;
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