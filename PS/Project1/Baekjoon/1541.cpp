#include <iostream>
#include <vector>
#include <string>
using namespace std;
int ans, temp, sign = 1;
int main() {
    string s; cin >> s; 
	int len = s.size();
    for (int i = 0; i <= len; i++)
    {
		if (s[i] == '+' || s[i] == '-' || i == len)
		{
			ans = ans + sign * temp;
			temp = 0;
			if (s[i] == '-') sign = -1;
		}
		else
		{
			temp *= 10; temp += s[i] - '0';
		}
    }
	cout << ans;
}
