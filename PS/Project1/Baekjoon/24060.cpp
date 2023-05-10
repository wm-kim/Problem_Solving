#include <iostream>
using namespace std;
int* arr, *tmp;
static int n, m, ans, cnt = 0;

void merge(int arr[], int left, int mid, int right)
{
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        tmp[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
    }
    while (i <= mid) tmp[k++] = arr[i++];
    while (j <= right) tmp[k++] = arr[j++];
    for (int a = left; a <= right; a++)
    {
        arr[a] = tmp[a - left];
        if (++cnt == m) { ans = arr[a]; return; }
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
	cin >> n >> m;
	arr = new int[n]; tmp = new int[n+1];
	for (int i = 0; i < n; i++) cin >> arr[i];
	mergeSort(arr, 0, n - 1);
	if (cnt < m) cout << -1 << "\n";
	else cout << ans << "\n";
    delete[] arr; delete[] tmp;
}