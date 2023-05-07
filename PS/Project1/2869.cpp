#include <iostream>
using namespace std;
int main()
{
	int a, b, v;
	cin >> a >> b >> v;
	/*
		int day = 0;
		while (1)
		{
			day++;
			v -= a;
			if (v <= 0) break;
			v += b;
		}
	*/ // 시간초과
	int day = (v - b - 1) / (a - b) + 1;
	cout << day << "\n";
}
