#include <iostream>
#include <string>
using namespace std;
int Findseries(int N)
{
    int i = 666;
    int series = 0;
    string target;
    while (1)
    {
		// i를 string으로 변환
        target = to_string(i);
        for (int j = 0; j < target.length() - 2; j++)
            if (target[j] == '6' && target[j + 1] == '6' && target[j + 2] == '6')
            {
                series++;
                if (series == N)
                    return i;
                break;
            }
        i++;
    }
}

int main() {
    int N;
    cin >> N;
    cout << Findseries(N);

    /* 다른 풀이
    int N, ans, cnt, temp;
    cin >> N;

	ans = 0; // 영화 제목
	cnt = 0; // 현재 몇번쨰 종말의 수인지

	while (cnt != N)
	{
		ans++;
		temp = ans;

		// 수에 6이 적어도 3개이상 들어가는지 판별
		while (temp != 0)
		{
			if (temp % 1000 == 666) // 종말의 숫자라면
			{
				cnt++;
				break;
			}
			else temp /= 10; // 일의 자리수 삭제
		}
	}
	cout << ans;
    */
}