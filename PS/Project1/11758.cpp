#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
struct Point { double x, y; };
int N;
double ans;
vector<Point> s;
double Product(const Point& p1, const Point& p2, const Point& p3)
{
    double result = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
    result -= p2.x * p1.y + p3.x * p2.y + p1.x * p3.y;
    return result / 2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	Point p1, p2, p3;
	cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
	cout << fixed;
	cout.precision(1);
	int res = Product(p1, p2, p3);
	if (res > 0) cout << 1;
	else if (res < 0) cout << -1;
	else cout << 0;
}