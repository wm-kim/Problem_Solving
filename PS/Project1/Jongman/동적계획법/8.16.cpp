// 타일링 방법의 수 세기
// tiling(n) = 2 * n 크기의 사각형을 타일(2*1) 로 덮는 방법의 수

#include <iostream>
using namespace std;

const int MOD = 100000007;
int cache[101];

int tiling(int width) {
	if (width <= 1) return 1;
	int& ret = cache[width];
	if (ret != -1) return ret;
	return ret = (tiling(width - 2) + tiling(width - 1)) % MOD;
}

// 삼각형 위의 최대 경로 세기
// 2개의 다른 동적 계획법 문제를 해결 - 최적화 문제 푼뒤 + 각 부분 문제마다 최적해의 개수 계산
// count(y, x) = y.x에서 시작해 맨 아래줄까지 내려가는 최대 경로 수
int n, triangle[100][100];
int countCache[100][100];
int cache2[100][100];

int path2(int y, int x) {
	if (y == n - 1) return triangle[y][x];
	int& ret = cache2[y][x];
	if (ret != -1) return ret;
	return ret = max(path2(y + 1, x), path2(y + 1, x + 1)) + triangle[y][x];
}

int count(int y, int x) {
	if (y == n - 1) return 1;
	int& ret = countCache[y][x];
	if (ret != -1) return ret;
	ret = 0;
	if (path2(y + 1, x + 1) >= path2(y + 1, x)) ret += count(y + 1, x + 1);
	if (path2(y + 1, x + 1) <= path2(y + 1, x)) ret += count(y + 1, x);
	return ret;
}