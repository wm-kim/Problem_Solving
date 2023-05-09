#include <iostream>
using namespace std;
const int MAX_SIZE = 100000;
int arr[MAX_SIZE];
class Stack {
public:
    Stack() : m_top(-1) {}
    void push(int val) {
        if (m_top == MAX_SIZE - 1) return;
        arr[++m_top] = val;
    }
    void pop() {
        if (m_top == -1) return; 
        m_top--;
    }
    int size() { return m_top + 1; }
    bool empty() { return m_top == -1; }
    int top() { return m_top == -1 ? -1 : arr[m_top]; }
private:
    int m_top;
};

int main()
{
    int k; cin >> k; Stack s;
	for (int i = 0; i < k; i++) {
		int n; cin >> n;
        if (n == 0) s.pop();
		else s.push(n);
	}
	int sum = 0;
	while (!s.empty()) { sum += s.top(); s.pop(); }
	cout << sum << endl;
}

