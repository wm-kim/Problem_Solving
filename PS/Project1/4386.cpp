#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int N; 
double ans;
struct Pos { int idx; float x, y; };
struct Line { int idx1, idx2; float dist; };
vector<Pos> s;
vector<Line> lines;
int st[101], rnk[101];
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
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		float x, y; cin >> x >> y;
		s.push_back({ i, x, y });
	}
	for (int i = 1; i <= N; i++) st[i] = i;
	for (int i = 0; i < s.size(); i++)
		for (int j = i + 1; j < s.size(); j++)
			lines.push_back({ i, j, dist(s[i], s[j]) });
	kruskal();
	cout.precision(2);
	cout << fixed << ans;
}