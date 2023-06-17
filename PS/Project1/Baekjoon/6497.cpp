#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int m, N, x, y, z;
struct Edge { int from, to, cost; };
vector<Edge> edges, mst;
int pre[200001], rnk[200001];
struct cmp { bool operator()(Edge& a, Edge& b) { return a.cost < b.cost; } };
int find(int x) {
	if (pre[x] == x) return x;
	return pre[x] = find(pre[x]);
}
void merge(int x, int y) {
	x = find(x); y = find(y);
	if (x == y) return;
	if (rnk[x] < rnk[y]) swap(x, y);
	pre[y] = x;
	if (rnk[x] == rnk[y]) rnk[x]++;
}
void kruskal()
{
	sort(edges.begin(), edges.end(), cmp());
	for (int i = 0; i < edges.size(); i++)
	{
		Edge edge = edges[i];
		if (find(edge.from) != find(edge.to))
		{
			mst.push_back(edge);
			merge(edge.from, edge.to);
		}
	}
}
int main()
{
	cin.tie(NULL); ios::sync_with_stdio(false);
	while (1)
	{
		cin >> m >> N;
		if (m == 0 && N == 0) break;

		for (int i = 0; i < m; i++) { pre[i] = i; rnk[i] = 0; }
		edges.clear(); mst.clear();
		int total_cost = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> x >> y >> z;
			edges.push_back({ x, y, z });
			total_cost += z;
		}
		kruskal();
		int mst_cost = 0; 
		for (int i = 0; i < mst.size(); i++) mst_cost += mst[i].cost;
		cout << total_cost - mst_cost << "\n";
	}
}