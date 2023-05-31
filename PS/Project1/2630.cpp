#include <iostream>
#include <vector>
using namespace std;
int arr[129][129]; int empty_cnt; int filled_cnt;
void constructSet(int x, int y, int size)
{
	if (size == 1) {
		arr[y][x] ? filled_cnt++ : empty_cnt++;
		return;
	}
    for (int i = y; i < y + size; i++)
        for (int j = x; j < x + size; j++)
            if (arr[i][j] != arr[y][x]) {
                int n = size / 2;
                constructSet(x, y, n); constructSet(x + n, y, n);
                constructSet(x, y + n, n); constructSet(x + n, y + n, n);
                return;
            }

    arr[y][x] ? filled_cnt++ : empty_cnt++;
}
int main()
{
	int n; cin >> n;
	for (int y = 1; y <= n; ++y) for (int x = 1; x <= n; ++x) cin >> arr[y][x];
	constructSet(1, 1, n);
	cout << empty_cnt << "\n" << filled_cnt << "\n";
}