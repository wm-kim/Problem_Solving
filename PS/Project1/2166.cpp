#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
struct Point { double x, y; };
int N;
double ans;
vector<Point> v;
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
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        Point p;
        cin >> p.x >> p.y;
        v.push_back(p);
    }
    for (int i = 1; i < N - 1; i++)
        ans += Product(v[0], v[i], v[i + 1]);
    cout << fixed;
    cout.precision(1);
    cout << abs(ans) << '\n';

    return 0;
}

// 삼각형의 외적을 이용하여 넓이를 계산
// 음수로 나올수도 있기 때문에 최종 결과값에 절대값을 붙여줘야 한다