// 데이터 복구
// k개의 부분 문자열 조각을 포함, 모두 알파벳 소문자로 구성
// 이러한 문자열 중 가장 짧은 것을 출력

// 접두 접미사 최대한 많이 겹치게 함
// 전처리 : 완전히 포함되는것은 지우기

// 완전 탐색 - 어떤 순서대로 출연할지 결정하고 최대한 겹치게 연결

// restore (last, used) 마지막에 출현한 조각 last, 지금까지 출현한 조각 집합 used가 주어질 때
// 나머지 조각을 추가해서 얻을 수 있는 overlap 최대
#include <string>
using namespace std;

const int MAX_N = 15;
int k;
string word[MAX_N];
int cache[MAX_N][1 << MAX_N], overlap[MAX_N][MAX_N];
int restore(int last, int used) {
	if (used == (1 << k) - 1) return 0;
	int& ret = cache[last][used];
	if (ret != -1) return ret;
	ret = 0;
	for (int next = 0; next < k; ++next) {
		if ((used & (1 << next)) == 0) {
			int cand = overlap[last][next] + restore(next, used + (1 << next));
			ret = max(ret, cand);
		}
	}
	return ret;
}

// 처음 호출시 last는 restore가 최대값을 반환한 시작단어로, used는 1 << last로 둔다.
string reconstruct(int last, int used) {
	if (used == (1 << k) - 1) return "";
	for (int next = 0; next < k; ++next) {
		// 이미 사용되었으면 제외
		if (used & (1 << next)) continue;
		// next를 사용했을 때 최적해와 같다면 next를 사용한다
		int ifUsed = restore(next, used + (1 << next)) +
			overlap[last][next];
		if (restore(last, used) == ifUsed)
		{
			return (word[next].substr(overlap[last][next]) + reconstruct(next, used + (1 << next)));
		}
	}

	return "**oops**";
}