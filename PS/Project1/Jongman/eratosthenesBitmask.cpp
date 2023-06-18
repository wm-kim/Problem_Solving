#include <cstring>
#include <cmath>
using namespace std;

// 에라토니스의 체,
#define MAX_N 100

int n;
// k 번째 원소가 참인지 알기 위해서는 k / 8 번째 원소의 k % 8 번째 비트가 켜져있는지 확인
unsigned char sieve[(MAX_N + 7) / 8];

// k가 소수인지 판별
inline bool isPrime(int k) {
	// >> 3은 8로나누는 것, 7과 and 연산은 8로 나눈 나머지를 구하는 것과 같다.
	return sieve[k >> 3] & (1 << (k & 7));
}

inline void setComposite(int k) {
	sieve[k >> 3] &= ~(1 << (k & 7));
}

// 비트마스크를 사용하는 에라토니스 체의 구현

void eratosthenes() {
	memset(sieve, 255, sizeof(sieve));
	setComposite(0);
	setComposite(1);
	int sqrtn = int(sqrt(n));
	for (int i = 2; i <= sqrtn; ++i) {
		if (isPrime(i))
			// i의 배수 j들에 대해 isPrime[j] = false로 둔다.
			// i * i 미만의 배수는 이미 지워졌으므로 신경 쓰지 않는다.
			for (int j = i * i; j <= n; j += i)
				setComposite(j);
	}
}

