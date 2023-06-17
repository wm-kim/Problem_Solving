#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool search(vector<int>& v, int left, int right, int num)
{
	while (left <= right) {
		int mid = (left + right) / 2;
		if (v[mid] == num) return true;
		else if (v[mid] < num) left = mid + 1;
		else right = mid - 1;
	}
	return false;
}
int main()
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n; cin >> n;
	vector<int> v(n); for (int i = 0; i < n; ++i) cin >> v[i];
	sort(v.begin(), v.end());
	int m; cin >> m;
	while (m--)
	{
		int num; cin >> num;
		cout << search(v, 0, n-1, num) << '\n';
	}
}

// 반복문 방식은 재귀 호출에 비해 스택 오버플로우 위험을 줄여주고, 약간의 성능 향상을 제공할 수 있습니다.
/*
bool binarySearch(vector<int>& v, int left, int right, int num) {
	if (left > right)
		return false;

	int mid = (left + right) / 2;

	if (v[mid] == num)
		return true;
	else if (v[mid] < num)
		return binarySearch(v, mid + 1, right, num);
	else
		return binarySearch(v, left, mid - 1, num);
}
*/