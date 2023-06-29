// 수강 철회 과목수 n
// r_i i과목의 등수, c_i i과목의 수강생 => 누적 등수 = sum r_i / sum c_i
// 수강 철회를 하면 누적등수 계산에서 제외
// 남는 과목이 k 이상이라면 장학금 받을 수 있을 때, 얻을 수 있는 최소 누적 등수
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int c[1000], r[1000];

bool decision(double average) {
	vector<double> v;
	for (int i = 0; i < n; ++i) {
		v.push_back(average * c[i] - r[i]); // v[i] 계산
	}
	sort(v.begin(), v.end());
	double sum = 0;
	for (int i = n - k; i < n; ++i) {
		sum += v[i];
	}
	return sum >= 0;
}

double optimize() {
	// 누적등수는 0~1 범위의 실수이다.
	//  lo를 0으로 설정하면 최소값이 0이 되는 경우를 고려할 수 없다.?
	double lo = -1e-9, hi = 1;
	for (int iter = 0; iter < 100; iter++) {
		double mid = (lo + hi) / 2;
		if (decision(mid)) hi = mid;
		else lo = mid;
	}
	return hi;
}

