#include <iostream>
#include <queue>
using namespace std;
int main() {
	cin.tie(NULL); cin.sync_with_stdio(false);
    int N; cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq; 
    while (N--) {
        int x; cin >> x;
        if (x == 0) {
            if (pq.empty()) cout << "0\n";
            else { cout << pq.top() << "\n"; pq.pop(); }
        }
        else pq.push(x);
    }
}