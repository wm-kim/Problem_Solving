#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
	while (1)
	{
		string s; getline(cin, s); stack<char> chars; string ans = "yes";
		if (s == ".") break;
		for (int i = 0; i < s.length() - 1; i++) // last char is always '.'
		{
			if (s[i] == '(' || s[i] == '[') chars.push(s[i]);
			if (s[i] == ')')
			{
				if (!chars.empty() && chars.top() == '(') chars.pop();
				else { ans = "no"; break; }
			}
			if (s[i] == ']')
			{
				if (!chars.empty() && chars.top() == '[') chars.pop();
				else { ans = "no"; break; }
			}
		}
		if (!chars.empty()) ans = "no";
		cout << ans << endl;
	}
}