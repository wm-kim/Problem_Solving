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
		// i�� string���� ��ȯ
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

    /* �ٸ� Ǯ��
    int N, ans, cnt, temp;
    cin >> N;

	ans = 0; // ��ȭ ����
	cnt = 0; // ���� ����� ������ ������

	while (cnt != N)
	{
		ans++;
		temp = ans;

		// ���� 6�� ��� 3���̻� ������ �Ǻ�
		while (temp != 0)
		{
			if (temp % 1000 == 666) // ������ ���ڶ��
			{
				cnt++;
				break;
			}
			else temp /= 10; // ���� �ڸ��� ����
		}
	}
	cout << ans;
    */
}