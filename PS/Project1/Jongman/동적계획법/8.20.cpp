// 비대칭 타일링 - 2*n의 크기의 직사각형을 2*1의 타일로 채우기
// 제한 사항 : 좌우 대칭이어서는 안됨

// 전체 경우의 수 - 대칭 타일링 수 
// 대칭 타일링 수 : n이 짝수인 경우, 홀수 인 경우

const int MOD = 100000007;
int cache[101];

int tiling(int width) {
	if (width <= 1) return 1;
	int& ret = cache[width];
	if (ret != -1) return ret;
	return ret = (tiling(width - 2) + tiling(width - 1)) % MOD;
}


int asymmetric(int width) {
	// 홀수
	if (width % 2 == 1) {
		return (tiling(width) - tiling(width / 2) + MOD) % MOD;
	}
	// 짝수
	int ret = tiling(width);
	ret = (ret - tiling(width / 2) + MOD) % MOD;
	ret = (ret - tiling(width / 2 - 2) + MOD) % MOD;
	return ret;
}

// 직접 세기 방법 : 좌우 대칭이 되는 것만 걸러내기
// 대칭인지 판별하기 위해서는 과거 선택 정보를 전부 전달해야함
// 전부 전달하지 않고서도 해결할 수 있는 방법 : 왼쪽 부터가 아니라 좌우 동시에 만들어가기

int cache2[101];

int asymmetric2(int width) {
	if (width <= 2) return 0;
	int& ret = cache2[width];
	if(ret != -1) return ret;
	ret = asymmetric2(width - 2) % MOD; // 재귀 호출
	ret = (ret + asymmetric2(width - 4)) % MOD; // 재귀 호출
	ret = (ret + tiling(width - 3)) % MOD;
	ret = (ret + tiling(width - 3)) % MOD;
}