// (가격, 선호도) 목록이 주어지고 주어진 예산안에서 선호도 최대화
// 각 물건을 무한정 가져갈 수 있음 
// 9.2 참고

#include <iostream>
using namespace std;

const int MAX_BUDGET = 1000;
int n, m, price[20], pref[20];
int cache[MAX_BUDGET + 1];

int sushi(int budget) {
	// 메모이제이션
	int& ret = cache[budget];
	if (ret != -1) return ret;
	ret = 0;
	for (int dish = 0; dish < n; ++dish) {
		if (budget < price[dish]) continue;
		ret = max(ret, sushi(budget - price[dish]) + pref[dish]);
	}
	return ret;
}

// MAX_BUDGET가 너무 클경우 반복적 동적 계획법을 사용 - 슬라이딩 윈도 기법 적용

int c[MAX_BUDGET + 1];
int sushi2() {
	int ret = 0;
	// bugget을 1부터 시작해서 m까지 순회하면서 최대 선호도 계산
	for (int budget = 1; budget <= m; ++budget) {
		c[budget] = 0;
		for (int dish = 0; dish < n; ++dish) {
			if (budget >= price[dish])
			{
				c[budget] = max(c[budget], c[budget - price[dish]] + pref[dish]);
			}
		}
		ret = max(ret, c[budget]);
	}
	return ret;
}

// 가격이 100의 배수이므로 최대 예산과 모든 가격을 100으로 나눈다.
// 최대가격은 20000
int sushi3() {
	int ret = 0;
	c[0] = 0;
	for (int budget = 1; budget <= m; ++budget) {
		int cand = 0;
		for (int dish = 0; dish < n; ++dish) {
			if (budget >= price[dish])
			{
				cand = max(cand, c[(budget - price[dish]) % 201] + pref[dish]);
			}
		}
		c[budget % 201] = cand;
		ret = max(ret, c[budget]);
	}
	return ret;
}

