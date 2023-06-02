#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<double, double> Pos;
struct Edge { Pos from, to; };
int parent[3001]; int group_size[3001];
vector<Edge> edges;
int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}
void merge(int x, int y) {
	x = find(x); y = find(y);
	if (x == y) return;
	if (group_size[x] < group_size[y]) swap(x, y);
	parent[y] = x;
	group_size[x] += group_size[y];
}
double crossProduct(const Pos& p1, const Pos& p2, const Pos& p3)
{
	double result = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
	result -= p2.first * p1.second + p3.first * p2.second + p1.first * p3.second;
	return result / 2;
}
bool isIntersect(Pos& p1, Pos& p2, Pos& p3, Pos& p4)
{
	double ab = crossProduct(p1, p2, p3) * crossProduct(p1, p2, p4);
	double cd = crossProduct(p3, p4, p1) * crossProduct(p3, p4, p2);
	if (ab == 0 && cd == 0)
	{
		if (p1 > p2) swap(p1, p2);
		if (p3 > p4) swap(p3, p4);
		return p1 <= p4 && p3 <= p2;
	}
	return ab <= 0 && cd <= 0;
}
int main()
{
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	int N, x1, x2, y1, y2, cnt, max_size;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		edges.push_back({ {x1, y1}, {x2, y2} });
	}
	for (int i = 0; i < N; i++)
	{
		parent[i] = i; group_size[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (isIntersect(edges[i].from, edges[i].to, edges[j].from, edges[j].to))
				merge(i, j);
		}
	}
	int group_cnt = 0;
	for (int i = 0; i < N; i++)
	{
		if (parent[i] == i) group_cnt++;
		max_size = max(max_size, group_size[i]);
	}
	cout << group_cnt << "\n" << max_size;
}