// 양자화 1000이하의 자연수들로 구성된 수열을 s가지의 자연수만 사용하여 양자화
// 오차의 제곱의 합이 최소치 구하기

// 최적의 부분 조건이 성립하지 않음 - 지금까지 사용한 n가지의 자연수를 무시할 수 없다.
// 지금 까지 사용한 숫자 집합을 입력으로 받아야함 - 1000C10 메모리가 너무 커짐

// 답의 형태 제한하기 : 답이 항상 어떤 구조를 가질 것이라 예측하고 강제하기
// 주어진 수열을 정렬하면 같은 숫자로 양자화 되는 숫자들은 항상 인접해있다.
// 수열을 s개로 묶는 문제가됨 - 최적 부분해가 성립

#include <iostream>
using namespace std;

const int INF = 987654321;
int n;
int A[101], pSum[101], pSqSum[101];
void preCacl() {} // A를 정렬하고 각 부분합을 계산한다.
int minError(int lo, int hi) {} // A[lo..hi] 구간을 하나의 숫자로 표현할 때 최소 오차의 합을 계산
int cache[101][11];
int quantize(int from, int parts) {
	// 모든 숫자를 다 양자화 했을 때
	if (from == n) return 0;
	// 아직 더 남았는데 더 묶을 수 없을 때
	if (parts == 0) return INF;
	int& ret = cache[from][parts];
	if (ret != -1) return ret;
	ret = INF;
	for (int partSize = 1; from + partSize <= n; ++partSize) {
		ret = min(ret, minError(from, from + partSize - 1) + quantize(from + partSize, parts - 1));
	}
	return ret;
}

