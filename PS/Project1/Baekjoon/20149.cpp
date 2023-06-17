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
void findIntersection(Pos& p1, Pos& p2, Pos& p3, Pos& p4)
{
	double A1 = p2.second - p1.second;
	double B1 = p1.first - p2.first;
	double C1 = A1 * p1.first + B1 * p1.second;
	double A2 = p4.second - p3.second;
	double B2 = p3.first - p4.first;
	double C2 = A2 * p3.first + B2 * p3.second;
	double det = A1 * B2 - A2 * B1;
	if (det == 0)
	{
		if (p2 == p3 && p1 <= p3) cout << p2.first << " " << p2.second;
		else if (p1 == p4 && p3 <= p1) cout << p1.first << " " << p1.second;
	}
	else
	{
		double x = (B2 * C1 - B1 * C2) / det;
		double y = (A1 * C2 - A2 * C1) / det;
		cout.precision(10);
		cout << fixed << x << " " << y << "\n";
	}
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