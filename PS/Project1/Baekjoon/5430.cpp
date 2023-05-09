#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;
int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	int t; cin >> t; string ans = "";
	while (t--)
	{
		string cmd; int size; cin >> cmd >> size;
		deque<int> dq; string arr; cin >> arr;
		string number = "";
		for (int i = 0; i < (int)arr.size(); i++)
		{
			if (arr[i] == ',' || arr[i] == ']')
			{
				if (!number.empty()) dq.push_back(stoi(number));
				number = "";
			}
			else if (arr[i] != '[') number += arr[i];
		}

		bool reversed = false; bool error = false;
		for (int i = 0; i < (int)cmd.size(); i++)
		{
			if (cmd[i] == 'R') reversed = !reversed;
			else if (cmd[i] == 'D')
			{
				if (dq.empty()) { cout << "error\n"; error = true;  break; }
				else
				{
					if (reversed) dq.pop_back();
					else dq.pop_front();
				}
			}
		}

		if (!error)
		{
			cout << "[";
			while (!dq.empty()) {
				if (reversed) {
					cout << dq.back();
					dq.pop_back();
				}
				else {
					cout << dq.front();
					dq.pop_front();
				}
				if (!dq.empty()) cout << ",";
			}
			cout << "]\n";
		}
	}
}