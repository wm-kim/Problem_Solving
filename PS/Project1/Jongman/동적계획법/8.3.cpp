#include <cstring>
using namespace std;

// 이항 계수 계산, nCr
int bino(int n, int r) {
	if (r == 0 || n == r) return 1;
	return bino(n - 1, r - 1) + bino(n - 1, r);
}

// 메모이제이션
int cache[30][30];
int bino2(int n, int r) {
	if (r == 0 || n == r) return 1;
	if (cache[n][r] != -1) return cache[n][r];
	return cache[n][r] = bino2(n - 1, r - 1) + bino2(n - 1, r);
}

// 이 책에서는 항상 한가지의 형태로 메모이제이션 구현 다음과 같은 형태
// 이 패턴을 그대로 따를 필요는 없지만 가장 좋다는 방식을 정해 일관되게 사용하는 것이 좋다.

int someObscureFunction(int a, int b) { // 반환값은 항상 음이 아닌 정수
	// 기저 사례
	if (...) return ...;
	int& ret = cache[a][b];
	if (ret != -1) return ret;

	// 여기에 답을 계산
	...
	return ret;
}

int main() {
	memset(cache, -1, sizeof(cache));
}
