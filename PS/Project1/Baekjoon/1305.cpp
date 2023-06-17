#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int L; string s;
int table[1000000];
void makeTable(string pattern)
{
	int j = 0;
	for (int i = 1; i < pattern.size(); i++)
	{
		while (j > 0 && pattern[i] != pattern[j])
			j = table[j - 1];
		if (pattern[i] == pattern[j]) table[i] = ++j;
	}
}
int main()
{
	cin >> L >> s;
	makeTable(s);
	int ans = L - table[L - 1];
	cout << ans;
}