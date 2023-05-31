#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, R, Q, U, V;
vector<int> graph[100001]; 
bool visited[100001];
int sizeOfSubtree[100001];
void dfs(int cur, int parent)
{
	visited[cur] = true;
	sizeOfSubtree[cur] = 1;
	for (int next : graph[cur])
	{
		if (next == parent) continue;
		if (!visited[next])
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
		graph[U].push_back(V);
		graph[V].push_back(U);
	}
	dfs(R, -1);
	for (int i = 0; i < Q; i++)
	{
		cin >> U;
		cout << sizeOfSubtree[U] << '\n';
	}
}