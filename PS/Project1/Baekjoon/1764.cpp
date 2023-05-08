#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
	int n, m; cin >> n >> m;
	set<string> s1; set<string> s2;
	for (int i = 0; i < n; i++) {
		string str; cin >> str; s1.insert(str);
	}
	for (int i = 0; i < m; i++) {
		string str; cin >> str; s2.insert(str);
	}
	set<string> s3;
	set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s3, s3.begin()));
	// don't use algorithm
	/*for (auto it = s1.begin(); it != s1.end(); it++) {
		if (s2.find(*it) != s2.end()) s3.insert(*it);
	}*/
	cout << s3.size() << "\n";
	for (auto& s : s3) cout << s << "\n";
}