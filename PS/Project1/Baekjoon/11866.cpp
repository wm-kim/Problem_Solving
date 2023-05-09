#include <iostream>
#include <queue>
using namespace std;
int main() {
	int n, m; cin >> n >> m;
	queue<int> q; for (int i = 1; i <= n; i++) q.push(i);
	cout << "<";
	while (!q.empty())
	{
		for (int i = 0; i < m - 1; i++) 
		{ 
			q.push(q.front()); 
			q.pop();
		}
		if (q.size() == 1) cout << q.front();
		else cout << q.front() << ", ";
		q.pop();
	}
	cout << ">\n";
}