// 드래곤 커브
// n = 1 FX
// X -> X + YF
// Y -> FX - Y

// n세대 문자열 구하기, 문자열중 p부터 l 까지의 글자만을 계산하는 프로그램 작성


// 간단한 문제부터 - 주어진 위치 한글자만을 계산해보기
#include <string>
#include <iostream>
#include <cassert>
using namespace std;
void curve(const string& seed, int generations) {
	if (generations == 0) {
		cout << seed << endl; return;
	}
	for (int i = 0; i < seed.size(); ++i) {
		if (seed[i] == 'X') {
			curve("X+FY", generations - 1);
		}
		else if (seed[i] == 'Y') {
			curve("FX-Y", generations - 1);
		}
		else
			cout << seed[i];
	}
}

// curve가 몇 글자를 출력할지 계산하는 동적 계획법 알고리즘
// xLength(n) : 문자열 X를 n세대 진화시킨 결과 길이
// yLength(n) : .. Y .. 

const int MAX = 1000000000 + 1;
int length[51]; // length[i] X나 Y를 i번 치환한 후의 길이

void precalc() {
	length[0] = 1;
	for (int i = 1; i <= 50; ++i) {
		length[i] = min(MAX, length[i - 1] * 2 + 2);
	}
}
const string EXPAND_X = "X+YF";
const string EXPAND_Y = "FX-Y";

char expand(const string& dragonCurve, int generations, int skip) {
	// 기저 사례
	if(generations == 0) {
		assert(skip < dragonCurve.size());
		return dragonCurve[skip];
	}
	for (int i = 0; i < dragonCurve.size(); ++i) {
		// 문자열이 확장되는 경우
		if (dragonCurve[i] == 'X' || dragonCurve[i] == 'Y') {
			if (skip >= length[generations]) skip -= length[generations];
			else if (dragonCurve[i] == 'X') return expand(EXPAND_X, generations - 1, skip);
			else return expand(EXPAND_Y, generations - 1, skip);
		}
		// 확장되지 않지만 건너 뛰어야 할 경우
		else if (skip > 0) {
			--skip;
		}
		// 답을 찾은 경우
		else {
			return dragonCurve[i];
		}
	}
	return '#'; // 이 줄은 수행되지 않음
}