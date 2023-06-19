#include <vector>
#include <array>
using namespace std;

void bubbleSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void selectionSort(vector<int>& v) {
	for (int i = 0; i < v.size(); ++i) {
		int minIndex = i;
		for (int j = i + 1; i < v.size(); ++j) {
			if (v[minIndex] > v[j]) {
				minIndex = j;
			}
		}
		swap(v[i], v[minIndex]);
	}
}

void insertionSort(vector<int>& A) {
	for (int i = 0; i < A.size(); ++i) {
		int j = i;
		while (j > 0 && A[j - 1] > A[j]) {
			swap(A[j - 1], A[j]);
			--j;
		}
	}
}

void insertionSort2(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		int key = arr[i];
		int j;
		for (j = i - 1; j >= 0 && arr[j] > key; j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}
}

void quickSort(int arr[], int left, int right) {
	if (left < right) {
		int pivot = partition(arr, left, right);
		quickSort(arr, left, pivot - 1);
		quickSort(arr, pivot + 1, right);
	}
}

int partition(int arr[], int left, int right) {
	int pivot = arr[right];
	int i = left - 1;
	for (int j = left; j < right - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[right]);
	return i + 1;
}

void merge(int arr[], int left, int mid, int right) {
	vector<int> temp(0, right - left + 1);
	int i = left, j = mid + 1, k = 0;

	while (i <= mid && j <= right) {
		temp[++k] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
	}
	while (i <= mid) {
		temp[k++] = arr[i++];
	}
	while (j <= right) {
		temp[k++] = arr[j++];
	}
	for (i = left; i <= right; ++i) {
		arr[i] = temp[i - left];
	}
}

void countingSort(int arr[], int n, int range) {
	vector<int> count(0, range + 1);
	vector<int> output(0, n);

	for (int i = 0; i < n; i++) count[arr[i]]++;
	for (int i = 1; i <= range; i++) count[i] += count[i - 1];

	for (int i = n - 1; i >= 0; i--) output[--count[arr[i]]] = arr[i];
	for (int i = 0; i < n; i++) arr[i] = output[i];
}

void radix_sort(int arr[], int n) {
	int max_num = arr[0];
	for (int i = 1; i < n; i++) if (arr[i] > max_num) max_num = arr[i];
	for (int exp = 1; max_num / exp > 0; exp *= 10) {
		countingSort(arr, n, exp);
	}
}

#include <queue>

int maxValue;
queue<int> Q[10];
void Radix_sort(vector<int>& arr) {
	int radix = 1;
	while (1)
	{
		if (radix >= maxValue) break;
		radix = radix * 10;
	}
	for (int i = 1; i < radix; i *= 10) {
		for (int j = 0; j < arr.size(); j++) {
			int K = (arr[j] / i) % 10;
			Q[K].push(arr[j]);
		}
		int Idx = 0;
		for (int j = 0; j < 10; j++) {
			while (!Q[j].empty()) {
				arr[Idx] = Q[j].front(); Q[j].pop();
				Idx++;
			}
		}
	}
}

