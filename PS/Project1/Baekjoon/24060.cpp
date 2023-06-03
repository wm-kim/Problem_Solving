#include <iostream>
using namespace std;
int* arr, *tmp;
static int N, m, ans, cnt = 0;

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
	cin >> N >> m;
	arr = new int[N]; tmp = new int[N+1];
	for (int i = 0; i < N; i++) cin >> arr[i];
	mergeSort(arr, 0, N - 1);
	if (cnt < m) cout << -1 << "\n";
	else cout << ans << "\n";
    delete[] arr; delete[] tmp;
}