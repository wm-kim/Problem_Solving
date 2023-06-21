// LIS

#include <vector>
using namespace std;
// 완전 탐색
int lis(const vector<int>& A) {
	if (A.empty()) return 0;
	int ret = 0;
	for (int i = 0; i < A.size(); ++i) {
		vector<int> B;
		for (int j = i + 1; j < A.size(); ++j) {
			// A[i]를 수열의 첫번째로 선택하고 이보다 큰 수들의 수열을 B로 저장하여 재귀호출
			if (A[i] < A[j]) B.push_back(A[j]);
		}
		// B에서 얻은 LIS를 A[i] 뒤에 붙이면됨
		ret = max(ret, 1 + lis(B));
	}
	return ret;
}

// 입력이 정수의 배열이라 메모이제이션이 까다로움 - 더 간단하게 표현하는 방법

int n;
int cache[100], S[100]; // cache는 S[start]에서 시작하는 증가 부분 수열 중 최대 길이

int lis2(int start) {
	int& ret = cache[start];
	if (ret != -1) return ret;
	// 항상 S[start]는 있기 때문에 길이는 최하 1
	ret = 1;
	for (int next = start + 1; next < n; ++next) {
		if (S[start] < S[next]) ret = max(ret, lis2(next) + 1);
	}
	return ret;
}

int maxLen = 0;
int main() {
	for (int begin = 0; begin < n; ++begin) {
		maxLen = max(maxLen, lis2(begin));
	}
}

// O(NlogN 풀이도 존재한다)
//  C[i] = 지금까지 만든 부분 배열이 갖는 길이 i인 LIS의 부분 수열 중 마지막 값


// S[-1] = -inf, lis2(-1)를 호출하면 -inf 부터 시작하므로 모든 시작위치를 자동으로 시도
// start에 -1이 주어질 수 있기 때문에 cache[start + 1]을 씀
// lis(-1) 호출
int lis3(int start)
{
	int& ret = cache[start + 1];
	if (ret != -1) return ret;

	ret = 1;
	for (int next = start + 1; next < n; ++next) {
		if (start == -1 || S[start] < S[next]) {
			ret = max(ret, lis3(next) + 1);
		}
	}
	return ret;
}

