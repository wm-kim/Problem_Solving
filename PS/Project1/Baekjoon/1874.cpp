#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main()
{
	int n; cin >> n; vector<int> v(n); stack<int> s; string ans = "";
	for (int i = 0; i < n; i++) cin >> v[i];
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i] > index)
		{
			for (int j = index + 1; j <= v[i]; j++) { s.push(j); ans += "+\n"; }
			index = v[i]; s.pop(); ans += "-\n";
		}
		else // v[i] < index (v[i] == index is impossible)
		{
			if (s.empty()) { cout << "NO\n"; return 0; }
			while (s.top() > v[i]) { s.pop(); ans += "-\n"; }
			if (s.top() == v[i]) { s.pop(); ans += "-\n"; }
			else { cout << "NO\n"; return 0; }
		}
	}
	cout << ans;
}

/*
stack<int> st;
vector<char> v;
int main() {
	int n, cnt=1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		while (cnt <= x) {
			v.push_back('+');
			st.push(cnt);
			cnt++;
		}

		if(x == st.top()) {
			st.pop();
			v.push_back('-');
		}
		else {
			cout << "NO";
			return 0;
		}
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}
*/