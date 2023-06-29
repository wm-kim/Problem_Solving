// 고속도로, N개의 도시를 지나는데
// L_i 시작점으로부터 도시까지의 거리
// i 번째 도시까지 남은 거리를 나타내는 표지판 : M_i 미터 전부터 시작해서 도착할때까지 G_i 미터 간격으로 설치

// 시작점으로 부터 여향하면서 보게되는 k번째 표지판 위치를 계산
// 한 위치에 표지판이 여러개 있으면 한개로 세기

// 거리가 너무 길기 때문에 단순한 알고리즘으로는 해결 불가능
// 최적화문제는 아니지만, 이것 또한 최적화 문제로 바꿔서 해결 가능

// decision(x) : 시작점으로 부터 x미터 지점까지 가면서 K개 이상의 표지판을 만날 수 있는가?
// 원하는 답이 D라면 decision(D - 1) = false, decision(D) = true
#include <vector>
using namespace std;

int n, k;
int l[5000], m[5000], g[5000];

bool decision(int dist) {
	int ret = 0;
	for (int i = 0; i < n; ++i) {
		if (dist >= l[i] - m[i]) {
			ret += (min(dist, l[i]) - (l[i] - m[i])) / g[i] + 1;
		}
	}
	return ret >= k;
}

int optimize() {
	int lo = -1, hi = 8030001;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2; // 정수형 나눗셈이다.
		if (decision(mid)) hi = mid;
		else lo = mid;
	}
	return hi;
}