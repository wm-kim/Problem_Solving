// 와일드 카드
// 패턴과 파일명의 집합이 주어질때 패턴과 대응되는 파일명들을 팢아내는 프로그램

// *로 쪼개기
// 패턴을 쪼개지 않고도 구현 가능

#include <string>
using namespace std;

// w는 패턴, s는 문자열
bool match(const string& w, const string& s)
{
	int pos = 0;
	while (pos < s.size() && pos < w.size() && (w[pos] == '?' || w[pos] == s[pos])) {
		++pos;
	}
	// 더 이상 대응 할 수 없으면 왜 while문이 끝나는지 확인
	// 1. 패턴 끝에 도달 한 경우 : 문자열도 끝났어야지 대응이된다.
	if (pos == w.size()) return pos == s.size();

	// 2. *을 만나서 끝난 경우, *에 몇글자를 대응해야할 지 재귀호출로 확인
	if (w[pos] == '*') {
		for (int skip = 0; pos + skip <= s.size(); ++skip) {
			if (match(w.substr(pos + 1), s.substr(pos + skip)))
				return true;
		}
	}

	return false;
}

int cache[101][101];
string S, W;
// 두 문자열의 시작 위치만을 넘겨 매번 문자열 객체를 생성하는 수고를 덜음
bool matchMemoized(int w, int s) {
	int& ret = cache[w][s];
	if (ret != -1) return ret;
	while (s < S.size() && w < W.size() && W[w] == '?' || W[w] == S[s]) {
		++w, ++s;
	}
	// 다른 분해방법 더 빠르다. O(N^3) -> O(N^2)
	// if (s < S.size() && w < W.size() && W[w] == '?' || W[w] == S[s]) {
			// return ret = matchMemoized(w + 1, s + 1);
	// }
	if (w == W.size()) return ret = (s == S.size());
	if (W[w] == '*')
	{
		for (int skip = 0; skip + s <= S.size(); ++skip) {
			if (matchMemoized(w + 1, s + skip)) return ret = 1;
		}
		// 매 단계에서 *에 아무글자도 대응시키지 않을 것인지, 아니면 한 글자를 더 대응시킬지 결정
		/*if (matchMemoized(w + 1, s) || (s < S.size() && matchMemoized(w, s + 1)))
			return ret = 1;*/
	}
	return ret = 0;
}

