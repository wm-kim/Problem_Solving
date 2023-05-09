#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; int index; cin >> n >> index; queue<pair<int, int>> q; priority_queue<int> pq;
		for (int i = 0; i < n; i++) { int p; cin >> p; q.push({ i, p }); pq.push(p); }
		int count = 0;
		while (!q.empty())
		{	
			if (pq.top() == q.front().second)
			{
				count++;
				if (q.front().first == index) { cout << count << endl; break; }
				else { q.pop(); pq.pop(); }
			}
			else
			{
				q.push(q.front()); q.pop();
			}
		}
	}
}