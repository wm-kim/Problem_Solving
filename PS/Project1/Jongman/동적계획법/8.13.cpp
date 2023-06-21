// 합친 LIS

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const long long NEGINF = numeric_limits<long long>::min();
int n, m, A[100], B[100];
int cache[101][101];

// min(A[indexA], B[indexB]), max(A[indexA], B[indexB])로 시작하는
// 합친 증가 부분 수열의 최대 길이 반환

// indexA == indexB == -1 혹은 A[indexA] != B[indexB]라고 가정
int jlis(int indexA, int indexB) {
	// memoization
	int& ret = cache[indexA + 1][indexB + 1];
	if (ret != -1) return ret;

	ret = 2;
	long long a = (indexA == -1 ? NEGINF : A[indexA]);
	long long b = (indexB == -1 ? NEGINF : B[indexB]);
	long long maxElement = max(a, b);

	// 다음 원소 찾기
	for (int nextA = indexA + 1; nextA < n; ++nextA) {
		if (maxElement < A[nextA]) ret = max(ret, jlis(nextA, indexB) + 1);
	}
	for (int nextB = indexB + 1; nextB < m; ++nextB) {
		if (maxElement < B[nextB]) ret = max(ret, jlis(indexA, nextB) + 1);
	}
	return ret;
}

