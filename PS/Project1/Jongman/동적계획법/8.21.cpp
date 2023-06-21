// 폴리노미오
// 세로 단조 : 어떤 가로줄도 폴리노미오를 두번 교차하지 않는다
// n개의 정사각형으로 구성된 세로 단조 폴리노미오 개수 세기

// 첫번째 가로줄의 정사각형 개수 i개
// 나머지 n-i개로 좌우로 밀면서 아래로 붙여줌
// 경우의 수를 정확히 계산하기 위해서는 첫번 째 줄의 정사각형 수를 알아야함

// poly(n, first) = 첫줄에 first개의 정사각형이 들어가는 폴리노미오 수

const int MOD = 10 * 1000 * 1000;
int cache[101][101];

int poly(int n, int first) {
	if (n == first) return 1;
	int& ret = cache[n][first];
	if (ret != -1) return ret;
	ret = 0;
	for (int second = 1; second <= n - first; ++second) {
		int add = second + first - 1;
		add *= poly(n - first, second);
		add %= MOD;
		ret += add;
		ret %= MOD;
	}
	return ret;
}