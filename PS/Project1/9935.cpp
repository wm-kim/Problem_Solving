#if 0 // O(N^2)
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
bool isMatch(const stack<char>& stk, const string& bomb)
{
	stack<char> tmp = stk;
	for (int i = bomb.size() - 1; i >= 0; i--)
	{
		if (tmp.top() != bomb[i]) return false;
		else tmp.pop();
	}
	return true;
}
int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	string input, bomb, ans; cin >> input >> bomb;
	stack<char> stk; 
	for (int i = 0; i < input.size(); i++)
	{
		stk.push(input[i]);
		if (stk.size() >= bomb.size())
		{
			if (isMatch(stk, bomb))
				for (int j = 0; j < bomb.size(); j++) stk.pop();
		}
	}
	if (stk.empty()) cout << "FRULA";
	else
	{
		while (!stk.empty()) { ans = stk.top() + ans; stk.pop(); }
		cout << ans;
	}
}
#endif

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
bool isMatch(const string& str, const string& bomb)
{
    int strSize = str.size(), bombSize = bomb.size();
    for (int i = 0; i < bombSize; i++)
    {
        if (str[strSize - bombSize + i] != bomb[i])
            return false;
    }
    return true;
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string input, bomb, ans;
    cin >> input >> bomb;
    int inputSize = input.size();
    int bombSize = bomb.size();
    for (int i = 0; i < inputSize; i++)
    {
        ans += input[i];
        int ansSize = ans.size();
        if (ansSize >= bombSize && isMatch(ans, bomb))
            ans.resize(ansSize - bombSize); // also can use pop_back
		/*
		* for (int b = 0; b < bomb.length(); b++) {
			ans.pop_back();
		}
		*/
    }
    if (ans.empty()) cout << "FRULA";
    else cout << ans;
}