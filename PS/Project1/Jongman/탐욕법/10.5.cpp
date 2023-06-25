// n개의 초소, 반지름 r의 원 내부 감시
// 각 초소의 위치와 범위가 주어질때 모든 성벽을 감시하기 위한 최소 병사 수

#include <iostream>
#include <algorithm>
using namespace std;
const double pi = 2.0 * acos(0);
double y[100], x[100], r[100];
pair<double, double> ranges[100];
int n;
void convertToRange() {
	for (int i = 0; i < n; ++i) {
		double loc = fmod(2 * pi + atan2(y[i], x[i]), 2 * pi);
		double range = 2.0 * asin(r[i] / 2.0 / 8.0);
		ranges[i] = make_pair(loc - range, loc + range);
	}
	sort(ranges, ranges + n);
}

// 최적해가 0을 덮는 구간을 2개 넘개 포함할 수 없다.

const int INF = 987654321;
int n;
pair<double, double> ranges[100];
int SolveCircular() {
	int ret = INF;
	// 시작 위치의 오름차순으로 정렬
	sort(ranges, ranges + n);
	// 0을 덮을 구간 선택
	for (int i = 0; i < n; ++i) {
		if (ranges[i].first <= 0 || ranges[i].second >= 2 * pi) {
			double begin = fmod(ranges[i].second, 2 * pi);
			double end = fmod(ranges[i].first + 2 * pi, 2 * pi);
			// [begin, end] 선분을 주어진 구간을 사용해서 덮는다.
			ret = min(ret, 1 + solveLinear(begin, end));
		}
	}
	return ret;
}


int solveLinear(double begin, double end) {
	int used = 0, idx = 0;
	while (begin < end) {
		// begin보다 이전에 시작하는 구간 중 가장 늦게 끝나는 구간 찾는다.
		double maxCover = -1;
		while (idx < n && ranges[idx].first <= begin) {
			maxCover = max(maxCover, ranges[idx].second);
			++idx;
		}
		// 덮을 구간을 찾지 못한 경우
		if (maxCover <= begin) return INF;
		// 선분의 덮인 부분을 잘라낸다.
		begin = maxCover;
		++used;
	}
	return used;
}