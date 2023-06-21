// 울타리 잘라내기, 히스토그램
#include <vector>
using namespace std;
int bruteForce(const vector<int>& h) {
	int ret = 0;
	int N = h.size();
	for (int left = 0; left < N; ++left) {
		int minHeight = h[left];
		for (int right = left; right < N; ++right) {
			minHeight = min(minHeight, h[right]);
			ret = max(ret, (right - left + 1) * minHeight);
		}
	}
}

// 분할 정복
vector<int> h;
int solve(int left, int right) {
	if (left == right) return h[left];
	int mid = (left + right) / 2;
	int ret = max(solve(left, mid), solve(mid + 1, right));
	int lo = mid, hi = mid + 1;
	int height = min(h[lo], h[hi]);
	ret = max(ret, height * 2);
	// 사각형이 입력 전체를 덮을 때까지 확장
	while (left < lo || hi < right) {
		// 항상 너 높은 쪽으로 확장 - 귀류법으로 고려하는 사각 형에 반드시 최대 사각형이 있다는 것을 증명
		if (hi < right && (lo == left || h[lo - 1] < h[hi + 1])) {
			++hi;
			height = min(height, h[hi]);
		}
		else {
			--lo;
			height = min(height, h[lo]);
		}

		// 확장한 후 사각형 넓이
		ret = max(ret, height * (hi - lo + 1));
	}
	return ret;
}