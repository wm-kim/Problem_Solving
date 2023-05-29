#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;
int parent[201], rnk[201];
int find(int x)
{
	if (parent[x] == x) return x;
	else return parent[x] = find(parent[x]);
}
void merge(int x, int y)
{
	x = find(x); y = find(y);
	if (x == y) return;
	if (rnk[x] < rnk[y]) swap(x, y);
	parent[y] = x;
	if (rnk[x] == rnk[y]) rnk[x]++;
}
int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++) parent[i] = i;
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