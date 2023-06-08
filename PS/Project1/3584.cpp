#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int T, N, a, b, u, v, st[10001];
bool visited[10001];
void lca(int a, int b)
{
	visited[a] = true;
	while (st[a] != a)
	{
		a = st[a];
		visited[a] = true;
	}
	while (1)
	{
		if (visited[b]) { cout << b << "\n"; break; }
		b = st[b];
	}
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 1; i <= N; i++) { visited[i] = false; st[i] = i; }
		for (int i = 0; i < N - 1; i++) { cin >> a >> b; st[b] = a; }
		cin >> u >> v;
		lca(u, v);
	}
}

//두노드 u, v를 입력받으면 u부터 루트 노드까지 올라가면서 방문 표시를 합니다.
// 그리고 v에서 위로 거슬러 올라갈 때 만약 그곳이 u가 방문했던 곳이라면 최소 공통 조상입니다.