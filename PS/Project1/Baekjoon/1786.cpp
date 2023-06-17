#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
string T, P; 
int table[1000000];
vector<int> ans;
void makeTable(string P)
{
	int j = 0;
	for (int i = 1; i < P.size(); i++)
	{
		while (j > 0 && P[i] != P[j]) j = table[j - 1];
		if (P[i] == P[j]) table[i] = ++j;
	}
}
void KMP(string T, string P)
{
	int tSize = T.size();
	int pSize = P.size();
	int j = 0;
	for (int i = 0; i < tSize; i++)
	{
		while (j > 0 && T[i] != P[j]) j = table[j - 1];
		if (T[i] == P[j])
		{
			if (j == pSize - 1)
			{
				ans.push_back(i - pSize + 2);
				j = table[j];
			}
			else j++;
		}
	}
}
int main()
{
	getline(cin, T);
	getline(cin, P);
	makeTable(P);
	KMP(T, P);
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
}