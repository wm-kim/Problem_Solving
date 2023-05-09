#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int main() {
    int size, n; cin >> size >> n; deque<int> dq; 
	for (int i = 1; i <= size; i++) dq.push_back(i);
    int ans = 0; 
    while (n--)
    {
		int a; cin >> a; 
		int rotate_left = 0;
		while (dq.front() != a)
		{
			dq.push_back(dq.front()); dq.pop_front(); rotate_left++;
			// rotate(dq.begin(), dq.begin() + 1, dq.end()); rotate_left++;
		}
		ans += min(rotate_left, (int)dq.size() - rotate_left);
		dq.pop_front();
    }
	cout << ans << "\n";
}