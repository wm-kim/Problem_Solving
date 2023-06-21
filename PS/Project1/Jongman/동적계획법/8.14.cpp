// 원주율 외우기
// 조각들의 난이도 표가 주어짐
// 원주율의 일부가 입력으로 주어질 때 난의도 합을 최소화하도록 끊어 읽기(3자리 ~ 5자리), 최소 난이도 계산

#include <string>
using namespace std;

const int INF = 987654321;
string N;
int cache[10002];
int classify(int a, int b) {} // N[a..b] 구간 난이도 반환
int memorize(int begin) {
	// 수열의 끝에 도달 했을 경우
	if (begin == N.size()) return 0;
	int &ret = cache[begin];
	if (ret != -1) return ret;
	ret = INF;
	for (int L = 3; L <= 5; ++L) {
		if (begin + L <= N.size()) {
			ret = min(ret, memorize(begin + L) + classify(begin, begin + L - 1));
		}
	}
	return ret;
}