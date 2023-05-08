#include <iostream>
#include <string>
using namespace std;
int main() 
{
	string s; cin >> s;
	string list[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
	int count = 0;
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = 0; j < 8; j++)
		{
			string substr = s.substr(i, list[j].length());
			if (substr == list[j])
			{
				i += list[j].length() - 1;
				break;
			}
		}
		count++;
	}
	cout << count;
}
