// 탈옥 - 산길로만 이동
// 탈출 당일, 교도소와 인접한 마을 하나로 도망쳐 은신
// 매일 인접한 마을로 이동
// d일 후에 각 마을에 있을 확률

#include <vector>
using namespace std;

int n, d, p, q; // p에서 시작해 q까지 길이가 n+1인 경로를 모두 생성하여 확률의 합을 반환
int connected[51][51], deg[51]; // 차수
double search(vector<int>& path) {
	if (path.size() == d + 1) {
		// q에서 끝나지 않는다면 무효
		if (path.back() != q) return 0.0;
		// path의 출현 확률 계산
		double ret = 1.0;
		for (int i = 0; i + 1 < path.size(); ++i) {
			ret /= deg[path[i]];
		}
		return ret;
	}
	double ret = 0;
	// 경로의 다음 위치를 결정한다.
	for (int next = 0; next < n; ++next) {
		if (connected[path.back()][next]) {
			path.push_back(next);
			ret += search(path);
			path.pop_back();
		}
	}
	return ret;
}

// 메모이제이션 - 이대로는 할 수 없으므로 정보를 줄이기
// path가 쓰이는 용도 : 1. 현재 위치, 2. 길이(지난 날짜), 3. 확률 계산

// path 대신 here과 탈옥후 지난 날짜 days를 전달
// 전체 경로의 확률이 아니라, 남은 날짜만큼 움직여 q에 도달할 확률 계산

// search2(here, days) days일 째에 here에 숨어있을 때, 마지막에 q번에 있을 조건부 확률

double cache[51][101]; // -1로 초기화
double search2(int here, int days) {
	if (days == d) return (here == q ? 1.0 : 0.0);
	double& ret = cache[here][days];
	if (ret > -0.5) return ret;
	ret = 0.0;
	for (int there = 0; there < n; ++there) {
		if (connected[here][there])
			ret += search2(there, days + 1) / deg[here];
	}
	return ret;
}

// 계산의 순서를 반대 방향으로 바꾸기 - 더 빠르게 구현
// 반대쪽 q로부터 경로를 만들어 나가기

// search(here, days) = 탈옥 후 days일 째에 here번 마을에 숨어있을 확률
// 부분 문제의 정의를 바꿔서 q가 바뀔 때마다 모든 값을 재계산할 필요가 없다.
double search3(int here, int days) {
	if (days == 0) return (here == p ? 1.0 : 0.0);
	double& ret = cache[here][days];
	if (ret > -0.5) return ret;
	for (int there = 0; there < n; ++there) {
		if (connected[here][there]) {
			ret += search3(there, days - 1) / deg[there];
		}
	}
	return ret;
}