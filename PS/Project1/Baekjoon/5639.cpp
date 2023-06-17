#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int preord[100001];
void GetPostOrder(int start, int end)
{
	if (start > end) return;
	int root = preord[start];
	int idx = start + 1;
	while (idx <= end && preord[idx] < root) idx++;
	GetPostOrder(start + 1, idx - 1);
	GetPostOrder(idx, end);
	cout << root << '\n';
}
int main()
{
	int i = 1, num;
	while (cin >> num) preord[i++] = num;
	GetPostOrder(1, i - 1);
}