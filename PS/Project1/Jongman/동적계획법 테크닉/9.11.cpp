// kth LIS

// 일반 k번쨰 답 구하기
// 1. 답의 수를 세는 문제를 푼다
// 2. 답의 수를 기반으로 답안을 재구성한다.

// 최적화 문제 + 경우의 수 세기 
// 1. 바탕이 되는 최적화 문제를 푼다
// 2. 최적화 문제의 최적해를 세는 문제를 푼다
// 3. 답의 수를 기반으로 답안을 재구성한다.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 2000000000 + 1;
int n;
int cacheLen[501], cacheCnt[501], S[500];
// S[start]에서 시작하는 증가부분 수열의 최대 길이를 반환한다.
// lis(-1)
int lis3(int start) {
	int& ret = cacheLen[start + 1];
	if(ret != -1) return ret;
	// S[start]가 있기 때문에 길이 최하 1
	ret = 1;
	for (int next = start + 1; next < n; ++next) {
		if (start == -1 || S[start] < S[next]) {
			ret = max(ret, lis3(next) + 1);
		}
	}
	return ret;
}

// LIS 개수 구하기
// lis3(i) = lis3(j) + 1 이 조건이 성립하지 않는다면 S[i]는 S[j] 뒤에 올수는 있지만 LIS는 만들지 못한다.
int count(int start) {
	if (lis3(start) == 1) return 1;
	int& ret = cacheCnt[start + 1];
	if (ret != -1) return ret;
	ret = 0;
	for (int next = start + 1; next < n; ++next) {
		if ((start == -1 || S[start] < S[next]) && lis3(start) == lis3(next) + 1)
		{
			ret = min<long long>(MAX, (long long)ret + count(next));
		}
	}
	return ret;
}

// skip = k - 1부터 시작
// S[start]에서 시작하는 LIS중 k번째 것을 계산해 lis에 저장한다.
void reconstruct(int start, int skip, vector<int>& lis) {
	// S[start]에서 부터 시작하는 LIS의 첫번째 수는 항상 S[start]
	if (start != -1) lis.push_back(S[start]);
	// (S[next], next)를 저장
	vector<pair<int, int>> followers;
	for (int next = start + 1; next < n; ++next) {
		if ((start == -1 || S[start] < S[next]) && lis3(start) == lis3(next) + 1)
			followers.push_back(make_pair(S[next], next));
	}
	sort(followers.begin(), followers.end());
	for (int i = 0; i < followers.size(); ++i) {
		int idx = followers[i].second;
		int cnt = count(idx);
		if (cnt <= skip) skip -= cnt;
		else {
			reconstruct(idx, skip, lis);
			break;
		}
	}
}

// 기저 사례가 없는 이유 : LIS가 1이면 바로 종료하도록 할 수 있지만
// followers에 아무것도 들어가지 않아 곧바로 종료함.
