#include <iostream>
using namespace std;
const int MAX_SIZE = 10000;
class Stack {
public:
    Stack() : m_top(-1) {}
    void push(int val) {
        if (m_top == MAX_SIZE - 1) return;
        m_data[++m_top] = val;
    }

    void pop() {
        if (m_top == -1) {
            std::cout << "-1" << std::endl;
            return;
        }
        std::cout << m_data[m_top--] << std::endl;
    }

    int size() { return m_top + 1; }
    bool empty() { return m_top == -1; }
    int top() { return m_top == -1 ? -1 : m_data[m_top]; }
private:
	int* m_data = new int[MAX_SIZE];
    int m_top;
};
int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	int n; cin >> n; Stack s;
    for (int i = 0; i < n; i++)
    {
		string cmd; cin >> cmd;
		if (cmd == "push") { int val; cin >> val; s.push(val); }
		else if (cmd == "pop") s.pop();
		else if (cmd == "size") cout << s.size() << endl;
		else if (cmd == "empty") cout << s.empty() << endl;
		else if (cmd == "top") cout << s.top() << endl;
    }
}