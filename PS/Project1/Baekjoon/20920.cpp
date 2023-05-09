#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
bool Compare(pair<string, int>& a, pair<string, int>& b)
{
	if (a.second == b.second)
	{
		if (a.first.length() == b.first.length()) return a.first < b.first;
		else return a.first.length() > b.first.length();
	}
	return a.second > b.second;
}
int main()	
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	int n, m; cin >> n >> m; unordered_map<string, int> countMap;
	for (int i = 0; i < n; i++)
	{
		string s; cin >> s; 
		if (s.length() >= m)
		{
			auto it = countMap.find(s);
			if (it == countMap.end()) countMap[s] = 1;
			else it->second++;
		}
	}
	vector<pair<string, int>> v(countMap.begin(), countMap.end());
	sort(v.begin(), v.end(), Compare);
	for (int i = 0; i < v.size(); i++) cout << v[i].first << '\n';
}