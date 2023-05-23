#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, x, sum, cnt;
int main()
{
	cin >> n; vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	cin >> x;
	int i = 0, j = n - 1;
	while (i < j)
	{
		sum = v[i] + v[j];
		if (sum == x) { cnt++; i++; j--; }
		else if (sum > x) { j--; }
		else if (sum < x) { i++; }
	}
	cout << cnt;
}

/* 다른 idea
* 
* 수열을 순회하면서 각 원소의 등장 횟수를 저장합니다. 
그리고 주어진 수 x에서 현재 원소를 뺀 나머지 값이 등장 했던 횟수를 찾아서 조합의 수를 셉니다. 
만약 현재 원소가 x의 절반인 경우는 한 번만 세고, 그 외의 경우에는 등장 횟수를 그대로 더합니다.
마지막으로 조합의 수를 2로 나눠서 출력합니다.
*/

/* 중복된 수가 없다면 hash set 을 이용해도 됨 */