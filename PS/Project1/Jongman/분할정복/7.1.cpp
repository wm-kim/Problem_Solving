// 1. divide 2. merge 3. base case

// 1~n 더하기
int fastSum(int n) {
	if (n == 1) return 1;
	// n이 홀수 일 때
	if (n % 2 == 1) return fastSum(n - 1) + n;
	return 2 * fastSum(n / 2) + (n / 2) * (n / 2);
}

// 어떻게 나누냐에 따라 부분 문제의 수가 달라짐
class SquareMatrix;
SquareMatrix identity(int n);

SquareMatrix pow(const SquareMatrix& A, int m) {
	if (m == 0) return identity(A.size());
	if (m % 2 > 0) return pow(A, m - 1) * A;
	SquareMatrix half = pow(A, m / 2);
	return half * half;
}
