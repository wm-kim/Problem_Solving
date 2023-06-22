// 반복적 동적 계획법

// 삼각형 최대 경로
// bottom-up 계산하면서 올라가면 필요한 값들을 항상 가지고 있다
#include <iostream>
using namespace std;
int n, triangle[100][100];
int C[100][100];
int iterative() {
	// 기저 사례를 계산한다
	for (int x = 0; x < n; ++x) {
		C[n - 1][x] = triangle[n - 1][x];
	}
	// 다른 부분을 계산한다
	for (int y = n - 2; y >= 0; --y) {
		for (int x = 0; x < y + 1; ++x) {
			C[y][x] = max(C[y + 1][x], C[y + 1][x + 1] + triangle[y][x]);
		}
	}
	return C[0][0];
}

// 슬라이딩 윈도우로 공간 복잡도 줄이기
int C2[2][100];
int iterative2() {
	// 기저 사례를 계산한다
	for (int x = 0; x < n; ++x) {
		C[n - 1][x] = triangle[n - 1][x];
	}
	// 다른 부분을 계산한다
	for (int y = n - 2; y >= 0; --y) {
		for (int x = 0; x < y + 1; ++x) {
			C[y % 2][x] = max(C[(y + 1) % 2][x], C[(y + 1)% 2][x + 1] + triangle[y][x]);
		}
	}
	return C[0][0];
}

// 피보나치
int fib(int n) {
	if (n <= 1) return n;
	int seq[3];
	seq[0] = 0; seq[1] = 1;
	for (int i = 2; i <= n; ++i) {
		seq[i % 3] = (seq[(i - 1) % 3] + seq[(i - 2) % 3]) % 100000;
	}
	return seq[n % 3];
}


// 피보나치 - 행렬 제곱
#include <vector>
using namespace std;

typedef vector<vector<int>> SquareMatrix;
SquareMatrix pow(const SquareMatrix& A, int n);
int fib3(int n) {
	if (n == 0) return 0;
	SquareMatrix W(2);
	W[0][0] = 0;
	W[0][1] = W[1][0] = W[1][1] = 1;
	return pow(W, n - 1)[1][1];
}