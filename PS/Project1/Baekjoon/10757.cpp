#include <iostream>
#include <vector>
using namespace std;
int main()
{
	string a, b; string ans = "";
	cin >> a >> b;
	int al = a.length(), bl = b.length();
	if (al < bl)
	{
		swap(a, b); swap(al, bl);
	}
	
	for (int i = 0; i < al - bl; i++)
		b = '0' + b;

	int carry = 0;
	for (int i = al; i > 0; i--) 
	{
		int sum = a[i - 1] - '0' + b[i - 1] - '0' + carry;
		ans += sum % 10 + '0';
		carry = sum / 10;
	}

	if (carry) ans += '1';
	
	for (int i = ans.length() - 1; i >= 0; i--) 
		cout << ans[i];
}
