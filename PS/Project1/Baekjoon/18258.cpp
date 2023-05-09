#include <iostream>
using namespace std;

int q[2000000];

class Queue {
private:
    int frontIdx = 0, rearIdx = 0; // 큐의 앞과 뒤 인덱스
public:
    void push(int x) { q[rearIdx++] = x; }
    void pop() { empty() ? cout << "-1\n" : cout << q[frontIdx++] << "\n"; }
    int size() { return rearIdx - frontIdx; }
    bool empty() { return frontIdx == rearIdx; }
    int front() { return empty() ? -1 : q[frontIdx]; }
    int back() { return empty() ? -1 : q[rearIdx - 1]; }
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    Queue q; int n, x; string cmd; 
    cin >> n;
    while (n--) {
        cin >> cmd;
        if (cmd == "push") cin >> x, q.push(x);
        else if (cmd == "pop") q.pop();
        else if (cmd == "size") cout << q.size() << "\n";
        else if (cmd == "empty") cout << q.empty() << "\n";
        else if (cmd == "front") cout << q.front() << "\n";
        else if (cmd == "back") cout << q.back() << "\n";
    }
    return 0;
}