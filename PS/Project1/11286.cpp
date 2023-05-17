#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
struct Compare {
    bool operator()(int a, int b) {
		if (abs(a) == abs(b)) return a > b;
        return abs(a) > abs(b);
    }
};
int main() {
    int N; cin >> N;
    priority_queue<int, vector<int>, Compare> pq;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        if (x != 0) pq.push(x);
        else {
            if (pq.empty()) cout << "0\n";
            else {
                int value = pq.top();
                cout << value << "\n";
                pq.pop();
            }
        }
    }
}