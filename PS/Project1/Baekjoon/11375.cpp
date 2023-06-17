#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1001
using namespace std;
vector<int> adj[MAX];
int match[MAX];
bool finish[MAX];
int N, M;

bool dfs(int x) {
	for (int i = 0; i < adj[x].size(); i++) {
		int next = adj[x][i];
		if (finish[next]) continue;
		finish[next] = true;
		if (match[next] == 0 || dfs(match[next])) {
			match[next] = x;
			return true;
		}
	}
	return false;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int num; cin >> num;
		for (int j = 0; j < num; j++) {
			int work; cin >> work;
			adj[i].push_back(work);
		}
	}

	int count = 0;
	for (int i = 1; i <= N; i++) {
		fill(finish, finish + MAX, false);
		if (dfs(i)) count++;
	}
	cout << count;
}