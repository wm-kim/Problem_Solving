#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int T, N, M, a, b;
int main()
{
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		for (int i = 1; i <= M; i++)
			cin >> a >> b;
		cout << N - 1 << "\n";
	}
}