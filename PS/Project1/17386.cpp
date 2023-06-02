#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Point { double x, y; };
double Product(const Point& p1, const Point& p2, const Point& p3)
{
    double result = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
    result -= p2.x * p1.y + p3.x * p2.y + p1.x * p3.y;
    return result / 2;
}
bool isIntersect(const Point& p1, const Point& p2, const Point& p3, const Point& p4)
{
	double ab = Product(p1, p2, p3) * Product(p1, p2, p4);
	double cd = Product(p3, p4, p1) * Product(p3, p4, p2);
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