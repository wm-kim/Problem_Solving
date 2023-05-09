#include <iostream>
using namespace std;
const char MAX_SIZE = 50;
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
    void clear() { m_top = -1; }
private:
    int m_top;
};
int main()
{
    int k; cin >> k; Stack st; 
    for (int i = 0; i < k; i++) {
        string s; cin >> s; string ans = "";
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == '(') st.push(1);
            else if (s[j] == ')')
            {
				if (st.empty()) { ans = "NO"; break; }
				else st.pop();
            }
		}
        if (ans == "")
        {
			if (st.empty()) ans = "YES";
			else ans = "NO";
        }
		cout << ans << '\n';
		st.clear();
	}
}

/*
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
    int k; cin >> k;

    while (k > 0) {
        k--; string input;
        cin >> input;

        stack<char> st;
        string answer = "YES";
        for (int i = 0; i < input.length(); i++) {
            if (input[i] == '(') {
                st.push(input[i]);
            }
            else if (!st.empty() && input[i] == ')' && st.top() == '(') {
                st.pop();
            }
            else {
                answer = "NO";
                break;
            }
        }
        if (!st.empty()) answer = "NO";

        cout << answer << endl;
    }
    return 0;
}
*/