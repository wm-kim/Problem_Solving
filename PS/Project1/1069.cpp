#if 0
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
double X, Y, D, T;
struct Pos { double x, y; Pos& operator*=(double d) { x *= d; y *= d; return *this; } };
bool operator==(const Pos& a, const Pos& b) { return a.x == b.x && a.y == b.y; }
Pos operator-(const Pos& a, const Pos& b) { return { a.x - b.x, a.y - b.y }; }
Pos operator+(const Pos& a, const Pos& b) { return { a.x + b.x, a.y + b.y }; }
double dist(const Pos& a, const Pos& b) { return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)); }
double sec, ans;
void bt(Pos cur)
{
	if (sec >= ans) return;
	if (cur == Pos{ 0, 0 })
	{
		ans = min(ans, sec);
		return;
	}
	
	cout << cur.x << ' ' << cur.y << '\n';
	Pos delta = { cos(atan2(cur.y, cur.x)), sin(atan2(cur.y, cur.x)) };
	if (cur.x < 0 && cur.y < 0) delta *= -1;
	cur = cur - delta; sec++;
	bt(cur); sec--; cur = cur + delta;
	
	delta *= D; 
	if (cur.x < 0 && cur.y < 0) delta *= -1;
	cur = cur - delta; sec += T;
	bt(cur); sec -= T; cur = cur + delta;
}

int main()
{
	cin >> X >> Y >> D >> T;
	ans = dist(Pos{ X, Y }, Pos{ 0, 0 });
	bt(Pos{ X, Y });
	cout.precision(9);
	cout << fixed << ans;
}
#endif

// 걷기 : 1초 1만큼
// 점프 : T초 D만큼
// 0, 0까지 가는데 최소시간 

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
double X, Y, D, T, ans;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> X >> Y >> D >> T;
	double d = sqrt(pow(X, 2) + pow(Y, 2));
	cout << fixed; cout.precision(9);
	if (D < T) cout << d << '\n';
	else
	{
		ans = d;
		int jump = d / D; // 점프 횟수
		d -= jump * D; // 남은 거리

		if (jump == 0) ans = min(ans, min(T + D - d, 2.0 * T));
		else ans = min(ans, min(jump * T + d, (jump + 1.0) * T));

		cout << ans << '\n';
	}
}

// jump == 0
// 1. 일직선으로 1번 점프 후, 지나친 거리를 되돌아 오는 경우
// 2. 꺾어서 2번 점프만에 가는 경우


// jump != 0
// 1. 최대 점프 한 후 남은 거리 걸어가는 경우
// 2. 최대 점프 + 점프 한번 더 해서 꺾어 가는 경우
