// 주어진 m개의 지점에 n개의 카메라를 설치할 때, 최소 간격의 최대치 반환

// optimization(locations, camera) : 최소 간격의 최대치 반환
// 변환 : decision(locations, cameras, gap) 모든 카메라의 간격이 gap이상이 되도록 하는 방법

// 탐욕법으로 쉽게 해결 가능, 첫번째 위치는 무조건 카메라 설치

#include <vector>
using namespace std;
bool decision(const vector<double>& location, int cameras, double gap) {
	double limit = -1;
	int installed = 0;
	for (int i = 0; i < location.size(); ++i) {
		if (limit <= location[i]) {
			++installed;
			// location + gap 이후는 되어야 카메라를 설치할 수 있다.
			limit = location[i] + gap;
		}
	}
	// 결과적으로 camera 대 이상을 설치할 수 있었으면 성공
	return installed >= cameras;
}

double optimize(const vector<double>& location, int cameras) {
	double lo = 0, hi = 241;
	// 왜 100번 순회하는지는 이분법 참고 13.2
	for (int it = 0; it < 100; ++it) {
		double mid = (lo + hi) / 2.0;
		if (decision(location, cameras, mid)) {
			lo = mid;
		}
		else {
			hi = mid;
		}
	}
	return lo;
}

// 이분법에서 탐색의 범위가 유한해지면 수치적 안정성이을 잃어버리게 된다.