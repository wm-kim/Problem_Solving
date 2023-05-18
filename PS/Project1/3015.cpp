#if 0
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int N, ans;
int main()
{
	cin >> N;
	vector<int> h(N); for (int i = 0; i < N; i++) cin >> h[i];
    stack<int> s;
	for (int i = 0; i < N; i++)
	{
        if (!s.empty() && s.top() < h[i])
        {
            ans += s.size() - 1; 
            while (!s.empty() && s.top() < h[i])
            {
                s.pop(); ans++;
            }
            ans += s.size();
        }
        s.push(h[i]);
	}
    cout << ans + s.size() - 1;
}
#endif

/*
* 위의 풀이는 같은 키의 사람이 없다고 가정하고 풀이한 것임
같은 키인 사람의 수를 따로 저장하여 따로 처리해야한다.
*/

#include <iostream>
#include<stack>
using namespace std;
int N, h; long long ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin >> N;
    stack<pair<int, int>> s;
    for (int i = 0; i < N; ++i) {
        cin >> h;
        while (!s.empty() && h > s.top().first) {
            ans += s.top().second;
            s.pop();
        }
        if (s.empty()) s.push(make_pair(h, 1));
        else 
        {
            if (s.top().first == h) {
                int cur = s.top().second;
                s.pop();
                if (!s.empty()) ans++;
                ans += cur;
                s.push(make_pair(h, cur + 1));
            }
            else {
                ans += 1;
                s.push(make_pair(h, 1));
            }
        }
    }
    cout << ans << '\n';
}