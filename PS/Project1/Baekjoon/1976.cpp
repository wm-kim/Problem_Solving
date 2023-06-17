#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;
int st[201], rnk[201];
int find(int x)
{
	if (st[x] == x) return x;
	else return st[x] = find(st[x]);
}
void merge(int x, int y)
{
	x = find(x); y = find(y);
	if (x == y) return;
	if (rnk[x] < rnk[y]) swap(x, y);
	st[y] = x;
	if (rnk[x] == rnk[y]) rnk[x]++;
}
int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++) st[i] = i;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			int x; cin >> x;
			if (x == 1) merge(i, j);
		}
	vector<int> plan(M + 1);
	for (int i = 1; i <= M; i++) cin >> plan[i];
	int root = find(plan[1]);
	for (int i = 2; i <= M; i++)
		if (root != find(plan[i]))
		{
			cout << "NO";
			return 0;
		}
	cout << "YES";
}