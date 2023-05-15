#include <iostream>
#include <stack>
using namespace std;
int main()
{
	int n, k; cin >> n >> k;
	stack<int> s; for (int i = 0; i < n; i++) { int x; cin >> x; s.push(x); }
	int count = 0;
	while (k > 0) 
	{
		int coin = s.top(); s.pop();
		if (k >= coin) { count += k / coin; k %= coin; }
	}
	cout << count;
}