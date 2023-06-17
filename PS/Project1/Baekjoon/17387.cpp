#if 0
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Point { double x, y; };
bool operator>(const Point& a, const Point& b) { if (a.x == b.x) return a.y > b.y; return a.x > b.x; }
bool operator<(const Point& a, const Point& b) { if (a.x == b.x) return a.y < b.y; return a.x < b.x; }
bool operator==(const Point& a, const Point& b) { return a.x == b.x && a.y == b.y; }
bool operator>= (const Point& a, const Point& b) { return a > b || a == b; }
bool operator<= (const Point& a, const Point& b) { return a < b || a == b; }
void swap(Point& a, Point& b) { Point tmp = a; a = b; b = tmp; }
double Product(const Point& p1, const Point& p2, const Point& p3)
{
	double result = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
	result -= p2.x * p1.y + p3.x * p2.y + p1.x * p3.y;
	return result / 2;
}
bool isIntersect(Point& p1, Point& p2, Point& p3, Point& p4)
{
	double ab = Product(p1, p2, p3) * Product(p1, p2, p4);
	double cd = Product(p3, p4, p1) * Product(p3, p4, p2);
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
	Point l1p1, l1p2, l2p1, l2p2;
	cin >> l1p1.x >> l1p1.y >> l1p2.x >> l1p2.y;
	cin >> l2p1.x >> l2p1.y >> l2p2.x >> l2p2.y;
	cout << isIntersect(l1p1, l1p2, l2p1, l2p2);
}
#endif

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<double, double> Pos;
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
	Pos l1p1, l1p2, l2p1, l2p2;
	cin >> l1p1.first >> l1p1.second >> l1p2.first >> l1p2.second;
	cin >> l2p1.first >> l2p1.second >> l2p2.first >> l2p2.second;
	bool intersect = isIntersect(l1p1, l1p2, l2p1, l2p2);
	cout << intersect << "\n";
	if (intersect) findIntersection(l1p1, l1p2, l2p1, l2p2);
}