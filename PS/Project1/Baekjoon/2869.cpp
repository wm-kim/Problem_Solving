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

/*
v - b에서 1을 빼는지 궁금하신 것 같습니다.
이는 나눗셈의 결과를 올림하기 위한 테크닉입니다.
(a - b)로 나누었을 때 나머지가 있으면, 즉 하루가 더 필요하면 그 다음 날로 넘어가야 하기 때문입니다.
이를 위해 -1을 해주고, 나눗셈을 수행한 후에 +1을 해줍니다.
이렇게 하면 나머지가 있을 경우에도 몫이 1 증가하게 되어 올림 효과를 얻을 수 있습니다.
*/
