// 어려운 문제
// 숫자 자리 위치만 바꿈, 이전에 m의 배수였음
// 이전 숫자의 경우의 수 구하기, 숫자를 바꾸기 전보다 더 작아야함

// 224나 242 경우 2번씩 세어짐 - 중복 - 같은 숫자가 여러개 있다면 그중 가장 먼저오는 것만을 선택하도록함

// 중복을 허용하지 안흔 방법 중 하나 : 이번에 사용할 자리수 바로 앞자리가 다음과 같은 경우에만 사용 
// 1. 없거나
// 2. 이번 자리수랑 다르거나
// 3. 이미 사용되었다면

// 완전 탐색
#include <string>
#include <iostream>
using namespace std;

string e, digits;  // digits는 e를 정렬한것
int n, m;
void generate(string price, bool taken[15]) {
	if (price.size() == n) {
		// 자리수가 같기 때문에 < 연산자를 이용해 비교 가능
		if (price < e) cout << price << endl;
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (!taken[i] && (i == 0 || digits[i - 1] != digits[i] || taken[i - 1])) {
			taken[i] = true;
			generate(price + digits[i], taken);
			taken[i] = false;
		}
	}
}

// taken - bitmask
// price 가 사용되는 정보 : n자리를 모두 만들었는지 판단, 다 만든 가격이 m의 배수인지, e보다 작은지
// price를 m으로 나눈 나머지만을 전달해도 마지막에 price가 m의 배수가 되는지 판단하는데 문제가 없다.
// less : e보다 작으면 true, 같으면 false

const int MOD = 100000007;
int cache[1 << 14][20][2]; // m은 최대 20

// index를 메모이제이션에 사용하지 않는 이유는 taken에 이미 정보가 포함되어있기 때문이다
int price(int index, int taken, int mod, int less) {
	if (index == n) {
		return (less && mod == 0) ? 1 : 0;
	}
	int& ret = cache[taken][mod][less];
	if (ret != -1) return ret;
	ret = 0;
	for (int next = 0; next < n; ++next) {
		if ((taken & (1 << next)) == 0) {
			// 과거의 가격은 새 가격보다 항상 작아야한다.
			if (!less && e[index] < digits[next]) continue;
			// 같은 숫자는 한번만 선택한다 (뒤집은 것)
			if (next > 0 && digits[next - 1] == digits[next] && (taken & (1 << (next - 1))) == 0) continue;
			int nextTaken = taken | (1 << next);
			int nextMod = (mod * 10 + digits[next] - '0') % m;
			int nextLess = less || (e[index] > digits[next]);
			ret += price(index + 1, nextTaken, nextMod, nextLess);
			ret %= MOD;
		}
	}
	return ret;
}



