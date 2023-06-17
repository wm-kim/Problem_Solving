#if 0 // 메모리 초과
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	int N, num; cin >> N;
	vector<stack<int>> v(N + 1);
	for (int i = 1; i <= N; ++i)
	{
		cin >> num;
		v[i].push(num);
		for (int j = 1; j < i; ++j)
			if (v[j].size() == 1 && v[j].top() < num) v[j].push(num);
	}
	for (int i = 1; i <= N; ++i)
	{
		if (v[i].size() == 2) cout << v[i].top() << " ";
		else cout << -1 << " ";
	}
}
#endif

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    vector<int> v(N); for (int i = 0; i < N; i++) cin >> v[i];
	
    vector<int> ans(N, -1);
    stack<int> s; // 아직 오른쪽에 더 큰 숫자를 찾지 못한 숫자의 인덱스가 저장
    for (int i = 0; i < N; i++) {
		// 새로운 숫자를 확인할 때마다 스택의 맨 위에 있는 숫자가 새로운 숫자보다 작은지 확인
        while (!s.empty() && v[s.top()] < v[i]) {
			// 만약 그렇다면, 새로운 숫자가 그 숫자의 오른쪽에 있는 더 큰 숫자이므로 결과 배열에 저장하고 스택에서 제거
            ans[s.top()] = v[i];
            s.pop();
        }
        s.push(i);
    }
    for (int i = 0; i < N; i++) cout << ans[i] << ' ';
}
