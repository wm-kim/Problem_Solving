#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool compare(string a, string b) 
{
    if (a.length() == b.length()) return a < b;
    else return a.length() < b.length();
}

int main() 
{
	int n; cin >> n;
    vector<string> strs(n);
    while (n--) cin >> strs[n];
    sort(strs.begin(), strs.end(), compare);
	strs.erase(unique(strs.begin(), strs.end()), strs.end());
	for (auto s : strs) cout << s << '\n';
}