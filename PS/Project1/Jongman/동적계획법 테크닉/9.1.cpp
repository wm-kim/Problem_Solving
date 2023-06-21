// 최적화 실제 계산 하기
// 모든 부문 문제마다 최적해 저장 - 느리고 메모리 많이 차지
// 각 부분문제마다 어떤 선택지를 택했을 때 최적해를 얻는지 기록
// 별도의 재귀함수를 이용해 되짚어가면서 최적해 생성 

// LIS

int n;
int cache[101], S[100], choices[101];
// cache는 S[start]에서 시작하는 증가 부분 수열 중 최대 길이
// lis4(-1) 부터 시작
int lis4(int start) {
	int& ret = cache[start + 1];
	if (ret != -1) return ret;
	// 항상 S[start]가 있기 때문에 길이는 최하 1
	ret = 1;
	int bestNext = -1;
	for (int next = start +1; next < n; ++next) {
		if (start == -1 || S[start] < S[next]) {
			int cand = lis4(next) + 1;
			if (cand > ret) {
				ret = cand;
				bestNext = next;
			}
		}
	}
	choices[start + 1] = bestNext;
	return ret;
}

#include <vector>
using namespace std;

// 이경우 굳이 재귀적으로 구현할 필요가 없다. 
// 하지만 재귀 호출을 이용하는 쪽이 설계하지 편한 경우가 많다.
void reconstruct(int start, vector<int>& seq) {
	if (start != -1) seq.push_back(S[start]);
	int next = choices[start + 1];
	if (next != -1) reconstruct(next, seq);
}