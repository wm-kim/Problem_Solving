// 지나온 경로로 가지치기 하기
// 알기 쉽지 않으니 간단히 조작을 가해보고 결과적으로 답이 더 좋아진다면 탐색을 중단하는 식

// TSP에서는 두개의 인접한 도시를 골라서 둘의 순서를 바꾼뒤 짧아지면 탐색 중단
// 반복 문을 돌면서 모든 도시쌍을 뒤집는 것이 아니라, 현재 도시 이전의 두 도시만 뒤집어 보기
// 경로가 최소한 자기 자신과 교차하지 않는 다는 것을 보여줌

#include <vector>
#include <map>
using namespace std;

const double INF = 1e200;
const int MAX = 30;
int n;
double dist[MAX][MAX];
double best;

bool pathSwappruning(const vector<int>& path) {
	if (path.size() < 4) return false;
	int p = path[path.size() - 4];
	int a = path[path.size() - 3];
	int b = path[path.size() - 2];
	int q = path[path.size() - 1];
	return dist[p][a] + dist[b][q] > dist[p][b] + dist[a][q];
}

// 시작 도시와 현재도시를 제외한 부분 경로를 뒤집어보고 더 짧아지는지 확인한다.
bool pathReversePruning(const vector<int>& path) {
	if (path.size() < 4) return false;
	int b = path[path.size() - 2];
	int q = path[path.size() - 1];
	for (int i = 0; i + 3 < path.size(); ++i) {
		int p = path[i];
		int a = path[i + 1];
		// [p, a .. b, q]를 [p, b .. a, q]로 바꿔 본다.
		if (dist[p][a] + dist[b][q] > dist[p][b] + dist[a][q]) return true;
	}
	return false;
}

// 더 현실에 가까운 답을 계산하기 위해 조금더 제약이 있는 문제
// 1. 한 간선은 최대 한 번만 선택
// 2. 선택하지 않은 간선을 모두 지웠을 때 그래프가 2개 이상으로 쪼개지면 안됨
// (MST) 크루스칼 사용

struct DisjointSet {
	// n개의 원소로 구성된 집합 자료 구조를 만든다.
	DisjointSet(int n);
	int find(int here);
	bool merge(int a, int b);
};

// 모든 도시 간의 도로를 길이 순으로 정렬해 저장
vector<pair<double, pair<int, int>>> edges;

double mstHeuristic(int here, const vector<bool>& visited) {
	// Kruskal MST
	DisjointSet sets(n);
	double taken = 0;
	for (int i = 0; i < edges.size(); ++i) {
		int a = edges[i].second.first, b = edges[i].second.second;
		if (a != 0 && a != here && visited[a]) continue;
		if (b != 0 && b != here && visited[b]) continue;
		if (sets.merge(a, b))
			taken += edges[i].first;
	}
	return taken;
}

// 메모이제이션 - 다 하기에는 메모리가 부족하므로 
// 남은 조각수가 k 이하일 때만 메모이제이션 적용
// 가지치기를 하는 함수는 쉽게 메모이제이션 하기 어려움
// 반환값이 현재 상태에만 영향을 받아야하는데, 가지치기를 하면 현재까지 오기위한 경로에 따라 반환이 달라질 수 있기 때문
// 경로까지 키로 사용하기에는, 경로는 서로 겹치지 않아 의미가 없다.
// 가지치기를 사용하지 않는 동적 계획법을 별도 작성해야함

// 남은 도시가 이 이하면 동적 계획법으로 바꾼다.
const int CACHED_DEPTH = 5;

// dp(here, visited) = cache[here][남은도시수][visited]
map<int, double> cache[MAX][CACHED_DEPTH + 1];

double dp(int here, int visited) {
	if (visited == (1 << n) - 1) return dist[here][0];
	int remaining = n - __builtin_popcount(visited);
	double& ret = cache[here][remaining][visited];
	if (ret > 0) return ret;
	ret = INF;
	// 다음 도시를 하나씩 시도한다.
	for (int next = 0; next < n; ++next) {
		if (visited & (1 << next)) continue;
		ret = min(ret, dp(next, visited + (1 << next)) + dist[here][next]);
	}
	return ret;
}
 
void search(vector<int>& path, int visited, double currentLength) {
	// 
	if (path.size() + CACHED_DEPTH >= n) {
		best = min(best, currentLength + dp(path.back(), visited));
		return;
	}
	// 생략 ...
}

double solve() {
	// 생략 ...
	for (int i = 0; i < MAX; ++i) {
		for (int j = 0; j <= CACHED_DEPTH; ++j) {
			cache[i][j].clear();
		}
	}
	// .. 생략 ..
}
