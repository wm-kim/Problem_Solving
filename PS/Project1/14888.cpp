#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n; int arr[11] = { 0, };
int pl, mi, mul, dv;
int maxVal = -1000000000, minVal = 1000000000;

void eval(int val, int pl, int mi, int mul, int dv)
{
	if (pl == 0 && mi == 0 && mul == 0 && dv == 0)
	{
		maxVal = max(maxVal, val);
		minVal = min(minVal, val);
		return;
	}

	int op_num = pl + mi + mul + dv;
	
	if (pl > 0) eval(val + arr[n - op_num], pl - 1, mi, mul, dv);
	if (mi > 0) eval(val - arr[n - op_num], pl, mi - 1, mul, dv);
	if (mul > 0) eval(val * arr[n - op_num], pl, mi, mul - 1, dv);
	if (dv > 0) eval(val / arr[n - op_num], pl, mi, mul, dv - 1);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	cin >> pl >> mi >> mul >> dv;
	eval(arr[0], pl, mi, mul, dv);
	cout << maxVal << "\n" << minVal << "\n";
}