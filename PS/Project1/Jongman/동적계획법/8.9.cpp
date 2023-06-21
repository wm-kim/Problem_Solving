// 삼각형 위의 최대 경로
// 오른쪽 혹은 아래쪽으로 내려 갈 수 있으며 맨 아래줄 까지 경로의 숫자 합을 최대화
#include <iostream>
using namespace std;

// 완탐 메모이제이션 - 메모리가 너무큼
const int MAX_NUMBER = 10;
int n, triangle[100][100];

// 현재위치가 y, x이고 지금까지 만난 수의 합이 sum일때 
// 맨 아래줄 까지 내려가면서 얻을 수 있는 최대 합
// 2^i 꼴의 숫자로만 이루어진 삼각형은 경로의 합이 다 달라서 완전탐색과 다를게 없다.
int cache[100][100][MAX_NUMBER * 100 + 1]; 

int path1(int y, int x, int sum) {
	if (y == n - 1) return sum + triangle[y][x];
	int& ret = cache[y][x][sum];
	if (ret != -1) return ret;
	sum += triangle[y][x];
	return ret = max(path1(y + 1, x + 1, sum), path1(y + 1, x, sum));
}

// y.x에서 맨 아래줄 까지 내려가는데 최대 경로는 sum이 얼마건 상관 없음
// 그러나 sum을 입력으로 받지 않으면 전체 경로의 합을 반환할 수 가 없다. 
// 전체가 아닌 부분 경로의 최대치로 바꾸기
// y.x부터 시작해서 맨 아래줄까지 내려가는 부분 경로의 최대 합

int cache2[100][100];

int path2(int y, int x) {
	if (y == n - 1) return triangle[y][x];
	int& ret = cache2[y][x];
	if (ret != -1) return ret;
	return ret = max(path2(y + 1, x), path2(y + 1, x + 1)) + triangle[y][x];
}

// 최적 부분 구조라고 함