// 셔플 모드 곡재생 - 잘어울리는 것 끼리 순서대로 재생
// mp3 플레이어 안에 있는 곡의 수 n,
// 좋아하는 곡의 수 m, 
// L_i = 곡의 길이 (i = 1..n) 범위 1~4
// T(i, j) = i후 j가 재생될 확률 
// k분 30초가 지났을 때 좋아하는 곡이 재생되고 있을 확률은?

// 모든 곡의 길이가 같았다면 8.24와 동일

// 반복적 동적 계획법
// start(time, song) = 재생을 시작한지 time분 후에 song 번 노래가 재생을 시작할 확률

#include <vector>
using namespace std;

int n, k, length[50];
double T[50][50];

vector<double> getProb1() {
	// c[time][song] : time분 후에 song 번 노래가 재생을 시작할 확률
	double c[5][50];
	memset(c, 0, sizeof(c));
	c[0][0] = 1.0;

	for (int time = 1; time <= k; ++time) {
		for (int song = 0; song < n; ++song) {
			double& prob = c[time % 5][song];
			prob = 0;
			for (int last = 0; last < n; ++last) {
				prob += c[(time - length[last] + 5) % 5][last] * T[last][song];
			}
		}
	}
	vector<double> ret(n);
	// song 번 노래가 재생되고 있을 확률을 구한다.
	for (int song = 0; song < n; ++song)
		for (int start = k - length[song] + 1; start <= k; ++start)
			ret[song] += c[start % 5][song];
	return ret;
}

// k가 너무 크면 너무 오래 걸린다.
// 
// 행렬의 거듭제곱 풀이

typedef vector<vector<int>> SquareMatrix;

vector<double> getProb2() {
	SquareMatrix W(4 * n);
	// 첫 3*n개의 원소는 그대로 복사해온다.
	for (int i = 0; i < 3 * n; ++i) {
		W[i][i + n] = 1.0;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			W[3 * n + i][(4 - length[j]) * n + j] = T[j][i];
		}
	}
	SquareMatrix Wk = W.pow(k);
	vector<double> ret(n);
	for (int song = 0; song < n; ++song)
		for (int start = 0; start < length[song]; ++start)
			ret[song] += Wk[(3 - start) * n + song][3 * n];
	return ret;
}