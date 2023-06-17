#include <iostream>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
using namespace std;
struct Circle { double x, y, r; };
int main()
{
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	Circle c1, c2;
	cin >> c1.x >> c1.y >> c1.r >> c2.x >> c2.y >> c2.r;
	double dist = sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
	cout << fixed; cout.precision(3);
	
	if (dist >= c1.r + c2.r) cout << 0.0;
	else if (dist <= abs(c1.r - c2.r))
	{
		double r = min(c1.r, c2.r);
		cout << M_PI * pow(r, 2);
	}
	else
	{
		double theta1 = acos((pow(c1.r, 2) + pow(dist, 2) - pow(c2.r, 2)) / (2 * c1.r * dist));
		double theta2 = acos((pow(c2.r, 2) + pow(dist, 2) - pow(c1.r, 2)) / (2 * c2.r * dist));
		double area1 = pow(c1.r, 2) * theta1 - pow(c1.r, 2) * sin(2 * theta1) / 2;
		double area2 = pow(c2.r, 2) * theta2 - pow(c2.r, 2) * sin(2 * theta2) / 2;
		cout << area1 + area2;
	}
}