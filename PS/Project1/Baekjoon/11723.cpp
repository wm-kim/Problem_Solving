#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 20;
int M, S, x;
int addBit(int bit, int pos) { return bit | (1 << pos - 1); }
int removeBit(int bit, int pos) { return bit & ~(1 << pos - 1); } // or  bit & !(1 << pos - 1); 
bool checkBit(int bit, int pos) { return bit & (1 << pos - 1); }
int toggleBit(int bit, int pos) { return bit ^ (1 << pos - 1); }
int all() { return (1 << N) - 1; }
int empty() { return 0; }
int main()
{
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> M;
	while (M--)
	{
		string cmd; cin >> cmd;
		if (cmd != "all" && cmd != "empty") cin >> x;
		if (cmd == "add") S = addBit(S, x);
		else if (cmd == "remove") S = removeBit(S, x);
		else if (cmd == "check") cout << checkBit(S, x) << '\n';
		else if (cmd == "toggle") S = toggleBit(S, x);
		else if (cmd == "all") S = all();
		else if (cmd == "empty") S = empty();
	}
}