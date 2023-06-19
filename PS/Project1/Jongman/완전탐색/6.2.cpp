// n개의 원소 중 m개를 고르는 모든 조합을 찾는 알고리즘
// 조합 탐색과 같음
#include <vector>
using namespace std;

void pick(int n, vector<int>& picked, int toPick) {
	if (toPick == 0) {
		// 출력
	}
	// 고를 수 있는 가장 작은 번호를 계산한다.
	int smallest = picked.empty() ? 0 : picked.back() + 1;
	for (int next = smallest; next < n; ++next) {
		picked.push_back(next);
		pick(n, picked, toPick - 1);
		picked.pop_back();
	}
}