#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int n; 
double ans;
struct Pos { int idx; float x, y; };
struct Line { int idx1, idx2; float dist; };
vector<Pos> v;
vector<Line> lines;
int parent[101], rnk[101];
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
float dist(Pos a, Pos b) { return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)); }
bool cmp(Line a, Line b) { return a.dist < b.dist; }
void kruskal()
{
	sort(lines.begin(), lines.end(), cmp);
	for (int i = 0; i < lines.size(); i++)
	{
		Line line = lines[i];
		if (find(line.idx1) != find(line.idx2))
		{
			merge(line.idx1, line.idx2);
			ans += line.dist;
		}
	}
}
int main()
{
	cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		float x, y; cin >> x >> y;
		v.push_back({ i, x, y });
	}
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 0; i < v.size(); i++)
		for (int j = i + 1; j < v.size(); j++)
			lines.push_back({ i, j, dist(v[i], v[j]) });
	kruskal();
	cout.precision(2);
	cout << fixed << ans;
}