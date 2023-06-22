// 순열의 사전 순 번호찾기
#include <vector>
using namespace std;

int factorials[12];
// X가 0..n-1의 순열일 때 사전순 번호 반환
int getIndex(const vector<int>& X) {
	int ret = 0;
	for (int i = 0; i < X.size(); ++i) {
		int less = 0;
		// X[i+1..] 중 X[i]보다 작은 수를 센다. 이것이 X 앞에오는 묶음의 수가 된다.
		for (int j = i + 1; j < X.size(); ++j) {
			if (X[j] < X[i]) {
				++less;
			}
		}
		ret += factorials[X.size() - i - 1] * less;
	}
	return ret;
}

// 외판원 문제 - 메모이제이션
// 남은 경로의 최소 길이 반환, 방문한적이 있는지 표시해야함 (비트마스크)

const int MAX = 15;
const int INF = 1e9;
int n, dist[MAX][MAX];
double cache[MAX][1 << MAX]; // -1로 초기화

double shorestPath2(int here, int visited) {
	if (visited == (1 << n) - 1) return dist[here][0];
	double& ret = cache[here][visited];
	if (ret >= 0) return ret;
	ret = INF;
	for (int next = 0; next < n; ++next) {
		if (visited & (1 << next)) continue;
		double cand = dist[here][next] + shorestPath2(next, visited + (1 << next));
		ret = min(ret, cand);
	}
	return ret;
}

