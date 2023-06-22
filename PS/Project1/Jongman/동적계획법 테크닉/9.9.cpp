// 모스 부호 
// n개의 -과 m개의 .으로 구성된 모든 신호를 담고 있는 사전
// -가 .먼저온다. 

// 사전의 k번째 신호를 출력하는 프로그램

// 모든 모스 신호를 만드는 완전 탐색 알고리즘
#include <iostream>
#include <string>
using namespace std;
// n 더 필요한 -의 개수, m은 더 필요한 .의 개수
void generate(int n, int m, string s) {
	if (n == 0 && m == 0) {
		cout << s << endl; return;
	}
	if (n > 0) generate(n - 1, m, s + "-");
	if (m > 0) generate(n, m - 1, s + "o");
}

// k-1개 건너뛰고 첫번째 신호를 출력 - 그러나 그 때까지 신호를 하나씩 만들어야함
int skip; // k-1로 초기화
void generate2(int n, int m, string s) {
	if (skip < 0) return;
	if (n == 0 && m == 0) {
		if (skip == 0) cout << s << endl;
		--skip;
		return;
	}
	if (n > 0) generate2(n - 1, m, s + "-");
	if (m > 0) generate2(n, m - 1, s + "o");
}


const int M = 1000000000 + 100;
int bino[201][201];// nCr
// 필요한 모든 이항계수 계산
void calcBino() {
	memset(bino, 0, sizeof(bino));
	for (int i = 0; i <= 200; ++i) {
		bino[i][0] = bino[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			bino[i][j] = min(M, bino[i - 1][j - 1] + bino[i - 1][j]);
		}
	}
}

// 앞으로 만들어질 신호의 개수는 n+mCn 
void generate3(int n, int m, string s) {
	if (skip < 0) return;
	if (n == 0 && m == 0) {
		if (skip == 0) cout << s << endl;
		--skip;
		return;
	}

	if (bino[n + m][n] <= skip)
	{
		skip -= bino[n + m][n];
		return;
	}
	if (n > 0) generate2(n - 1, m, s + "-");
	if (m > 0) generate2(n, m - 1, s + "o");
}


// 깔끔한 구현 - 완탐에서 시작하는게 아니라
// kth(n, m, skip) : n, m의 신호중 skip개를 건너뛰고 제일 먼저오는 신호를 반환하는 함수 
// 메모이제이션 사용할 필요도 없음

string kth(int n, int m, int skip) {
	// 나머지 부분은 'o'일수 밖에 없다
	if (n == 0) return string(m, 'o');
	if (skip < bino[n + m - 1][n - 1])
		return "-" + kth(n - 1, m, skip);
	return "o" + kth(n, m - 1, skip - bino[n + m - 1][n - 1]);
}

