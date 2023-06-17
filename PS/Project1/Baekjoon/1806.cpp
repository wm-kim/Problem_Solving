#if 0
#include <iostream>
#include <algorithm>
#include <vector>
#define INF 2000000000
using namespace std;
int N, S, ans = INF;
int main()
{
	cin >> N >> S;
	vector<int> v(N); for (int i = 0; i < N; i++) cin >> v[i];
	int i = 0, j = 0, sum = 0;
	while (i <= j && j < N)
	{
		if (sum >= S)
		{
			ans = min(ans, j - i);
			sum -= v[i++];
		}
		else sum += v[j++];
	}
	if (ans == INF) cout << 0 << "\n";
	else cout << ans << "\n";
}
#endif

// 반례 1
// 5 11
// 1 2 3 4 5

// 반례 2
// 5 5 
// 1 1 1 1 1
// https://dev-with-precious-dreams.tistory.com/121
// https://wadekang.tistory.com/5


/*
* 반례1 : 최적의 값 2 4 5를 찾지 못함.
left는 무조건 순차적으로 증가시켜야 한다는 것
 Right가 최소합을 만족시키면 더이상 right를 증가 시킬 필요가 없습니다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#define INF 2000000000
using namespace std;
int N, S, ans = INF, r, sum;
int main()
{
	cin >> N >> S;
	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	for (int l = 0; l < N; l++)
	{
		while (sum < S && r < N) sum += v[r++];
		if (sum >= S) ans = min(ans, r - l);
		sum -= v[l];
	}
	if (ans == INF) cout << 0 << "\n";
	else cout << ans << "\n";
}