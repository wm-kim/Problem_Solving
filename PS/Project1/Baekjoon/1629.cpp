#include <iostream>
using namespace std;
int pow(int a, int b, int c)
{
	if (b == 1) return a % c;
	long long tmp = pow(a, b / 2, c);
	if (b % 2 == 0) return tmp * tmp % c;
	else return tmp * tmp % c * a % c;
}
int main()
{
	int a, b, c; cin >> a >> b >> c;
	cout << pow(a, b, c) << "\n";
}