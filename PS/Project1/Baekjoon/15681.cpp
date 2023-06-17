#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, R, Q, U, V;
vector<int> adj[100001]; 
bool pre[100001];
int sizeOfSubtree[100001];
void dfs(int cur, int parent)
{
	pre[cur] = true;
	sizeOfSubtree[cur] = 1;
	for (int next : adj[cur])
	{
		if (next == parent) continue;
		if (!pre[next])
		{
			dfs(next, cur);
			sizeOfSubtree[cur] += sizeOfSubtree[next];
		}
	}
}
int main()
{
	cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> R >> Q;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> U >> V;
		adj[U].push_back(V);
		adj[V].push_back(U);
	}
	dfs(R, -1);
	for (int i = 0; i < Q; i++)
	{
		cin >> U;
		cout << sizeOfSubtree[U] << '\n';
	}
}