// 우물을 기어오르는 달펭이
// 맑은 날 2m, 비가 오면 하루 1m 오름.
// 비가 올 확률은 50%, m일 안에 우물 끝까지 올라갈 확률 (우물은 n 미터)


// 이전의 정보는 최소화한다.
// climb(days, climbed) : 크기가 days고 합이 climbed 일때 완성해서 합이 n 이상 되게하는 방법의 수


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX_N = 100;
int n, m;
int cache[MAX_N][2 * MAX_N + 1];
int climb(int days, int climbed) {
	if (days == m) return climbed >= n ? 1 : 0;
	int& ret = cache[days][climbed];
	return ret = climb(days + 1, climbed + 1) + climb(days + 1, climbed + 2);
}

// 비올 확률이 75%라면
// climb2(days, climbed) : ... m일 전까지 n미터 이상 기어올라갈 수 있을 확률
// = 0.75 * climb2(days + 1, climb + 1) + 0.25 * climb2(days + 1, climb + 1)