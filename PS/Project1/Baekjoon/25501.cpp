#include <iostream>
#include <string>
using namespace std;
static int c = 0;
bool recursion(const string& s, int l, int r) {
    c++;
    if (l >= r) { return true; }
    if (s[l] != s[r]) { return false; }
    return recursion(s, l + 1, r - 1);
}

bool isPalindrome(const string& s) {
    int n = s.size();
    return recursion(s, 0, n - 1);
}

int main() {
    int n; cin >> n;
	while (n--) {
		string s; cin >> s;
		cout << isPalindrome(s) << " " << c << "\n";
        c = 0;
	}
}