// Optical Character Recognition (난이도 상)
// 단어별로 인식한 결과가 주어졌을 때, 원본일 조건부확률이 가장 높은 문장 찾기
// B[i] : 첫단어로 출연할 확률
// T[i, j] : i번 단어 이후 j 번 단어일 확률
// M[i, j] : i번 단어가 j번 단어로 분류할 확률
// 그 후 인식한 문장이 R 주어짐


// 마르코프 연쇄
// P(Q|R)의 최대값 찾는 문제 (Q는 원문)
// 원문 Q를 만드는 과정을 n조각으로 잘라 각 재귀 호출마다 Q의 단어 하나를 정하기


int n, m; // m은 주어진 단어의 수, n은 문장 R의 단어의 수
int R[100]; // 문류기가 반환한 문장, 단어 번호로 변환
double T[501][501];
double M[501][501];
int choice[102][502];
double cache[102][502]; // 1.0로 초기화

// recognize (s, p) : Q[s-1]이 p일 때 Q[s..]를 적절히 채워서 만들 수 있는 g(Q[s]) * .. * g(Q[n-1]) 의 최대치
// 확률 값이 매우 작아 로그 값의 합을 구한다.
// 최대 g()곱의 로그값을 반환한다.
// previousMatch == Q[s-1] == p
double recognize(int segment, int previousMatch) {
	if (segment == n) return 0;
	double& ret = cache[segment][previousMatch];
	if (ret != 1.0) return ret;
	ret = -1e200;
	int& choose = choice[segment][previousMatch];
	// R[segment]에 대응되는 단어 찾기
	for (int thisMatch = 0; thisMatch < m; ++thisMatch) {
		double cand = T[previousMatch][thisMatch] + M[thisMatch][R[segment]] + recognize(segment + 1, thisMatch);
		if (ret < cand) {
			ret = cand;
			choose = thisMatch;
		}
	}
	return ret;
}

#include <string>
using namespace std;
// 입력받은 단어들의 목록
string corpus[501];
string reconstruct(int segment, int previousMatch) {
	int choose = choice[segment][previousMatch];
	string ret = corpus[choose];
	if (segment < n - 1) {
		ret = ret + " " + reconstruct(segment + 1, choose);
	}
	return ret;
}

