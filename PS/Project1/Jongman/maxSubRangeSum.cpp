#include <vector>
using namespace std;
const int MIN = numeric_limits<int>::min();

int inefficentMaxSum(const vector<int>& A) {
	int N = A.size(), ret = MIN;
	for (int i = 0; i < N; ++i) {
		for (int j = i; j < N; ++j) {
			int sum = 0;
			for (int k = i; k <= j; ++k) sum += A[k];
			ret = max(ret, sum);
		}
	}
	return ret;
}

int betterMaxSum(const vector<int>& A) {
	int N = A.size(), ret = MIN;
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = i; j < N; ++j) {
			sum += A[j];
			ret = max(ret, sum);
		}
	}
	return ret;
}

// 분할 정복 (재귀 + 탐욕)
int fastMaxSum(const vector<int>& A, int lo, int hi) {
	if (lo == hi) return A[lo];
	int mid = lo + hi / 2;
	// 두 두분에 걸쳐 있는 최대 합 구간 찾기 - greedy
	int left = MIN, right = MIN, sum = 0;
	for (int i = mid; i >= lo; --i) {
		sum += A[i];
		left = max(left, sum);
	}

	sum = 0;
	for (int j = mid + 1; j <= hi; ++j) {
		sum += A[j];
		right = max(right, sum);
	}
	int single = max(fastMaxSum(A, lo, mid), fastMaxSum(A, mid + 1, hi));
	return max(left + right, single);
}

// 동적 계획법 
// maxAt(i) = A[i]를 오른쪽 끝 구간의 최대합을 반환하는 함수
// maxAt(i) = max(0, maxAt(i-1)) + A[i]
int fastestMaxSum(const vector<int>& A) {
	int N = A.size(), ret = MIN, psum = 0;
	for (int i = 0; i < N; ++i) {
		psum = max(psum, 0) + A[i];
		ret = max(psum, ret);
	}
	return ret;
}


