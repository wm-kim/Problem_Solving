#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 2147483647;
int N, M, X, Y; double ans;
struct Pos { int x, y; };
struct Line { int idx1, idx2; double dist; };
vector<Pos> s;
vector<Line> lines;
int st[1001], rnk[1001];
double dist(Pos a, Pos b) { return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)); }
bool cmp(Line a, Line b) { return a.dist < b.dist; }
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
	cin >> N >> M;
	for (int i = 0; i < N; i++) { cin >> X >> Y; s.push_back({ X, Y }); }
	for (int i = 1; i <= N; i++) st[i] = i;
	for (int i = 0; i < s.size(); i++)
		for (int j = i + 1; j < s.size(); j++)
			lines.push_back({ i + 1, j + 1, dist(s[i], s[j]) });
	for (int i = 0; i < M; i++)
	{
		int a, b; cin >> a >> b;
		merge(a, b);
	}
	kruskal();
	cout.precision(2);
	cout << fixed << ans;
}