#include <iostream>
using namespace std;
int main()
{
	int n; cin >> n; int sum = 2;
	for (int i = 0; i < n; i++) sum += sum - 1;
	cout << fixed  << sum * sum << "\n";
}
