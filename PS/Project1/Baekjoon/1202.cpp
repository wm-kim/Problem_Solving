#if false
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 300001
typedef long long ll;
using namespace std;
struct Gem { int weight; int value; };
int N, K, bags[MAX], ans[MAX];
struct Cmp { bool operator()(Gem a, Gem b) { return a.value < b.value; } };
int main()
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	cin >> N >> K;
	priority_queue<Gem, vector<Gem>, Cmp> pq;
	for (int i = 1; i <= N; i++) {
		int M, V; cin >> M >> V;
		pq.push({ M,V });
	}
	for (int i = 1; i <= K; i++) cin >> bags[i];
	sort(bags + 1, bags + K + 1);
	int cnt = 0;
	while (cnt != K) {
		Gem cur = pq.top(); pq.pop();
		int idx = lower_bound(bags + 1, bags + K + 1, cur.weight) - bags;
		if (idx <= K) {
			if (!ans[idx]) {
				ans[idx] = cur.value;
				cnt++;
			}
			else {
				while (ans[idx]) { idx++; if (idx > K) break; }
				if (idx <= K) {
					ans[idx] = cur.value;
					cnt++;
				}
			}
		}
	}
	ll sum = 0;
	for (int i = 1; i <= K; i++) sum += ans[i];
	cout << sum;
}
#endif

// 가방에는 최대 1개의 보석을 넣을 수 있다.
// idea : Vn / Mn 을 내림차순으로 정렬 후 가장 가치가 높은 순으로 가방에 최대한 빈틈없이 넣는다.
// ans에는 가방에 넣은 보석의 가치를 저장한다.

// 먼저 보석을 가치 대비 무게로 정렬하려고 하고, 
// 가방을 무게로 정렬한 후에 각 보석에 대해 담을 수 있는 가장 가벼운 가방을 찾는다. 
// 그러나 이 접근 방식에는 몇 가지 문제가 있습니다.
// 
//가치 대비 무게로 보석을 정렬하면 어떤 보석이 다른 보석보다 더 가치있는 선택임을 보장할 수 없습니다.
// (1, 10), (2, 11)와 같은 보석, 그리고 가장 가벼운 가방이 2인 경우를 생각해보십시오.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 300001
using namespace std;
int N, K, bags[MAX];
pair<int, int> gems[MAX];
priority_queue<int, vector<int>, less<int>> pq;
long long solve() {
	sort(gems, gems + N); // 무게순 오름차순 정렬
	sort(bags, bags + K);
	int idx = 0;
	long long sum = 0;
	for (int i = 0; i < K; i++) {
		// i번째 가방에 들어갈 수 있는 모든 보석을 우선순위 큐에 넣는다.
		while (idx < N && bags[i] >= gems[idx].first) {
			pq.push(gems[idx].second);
			idx++;
		}
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}
	return sum;
}
int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	cin >> N >> K;
	for (int i = 0; i < N; ++i) cin >> gems[i].first >> gems[i].second;
	for (int i = 0; i < K; ++i) cin >> bags[i];
	cout << solve();
}