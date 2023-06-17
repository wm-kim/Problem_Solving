#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
int cnt[1000001];
int main()
{
	int N; cin >> N; 
	vector<int> v(N); vector<int> ans(N, -1); stack<int> s;
	for (int i = 0; i < N; i++) { cin >> v[i]; cnt[v[i]]++; }
	for (int i = 0; i < N; i++)
	{
		while (!s.empty() && cnt[v[s.top()]] < cnt[v[i]])
		{
			ans[s.top()] = v[i];
			s.pop();
		}
		s.push(i);
	}
	for (int i = 0; i < N; i++) cout << ans[i] << " ";
}