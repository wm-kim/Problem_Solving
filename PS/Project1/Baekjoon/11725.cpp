#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
vector<int> adj[100001]; int pre[100001];
void dfs(int start)
{
	for (int i = 0; i < adj[start].size(); i++)
	{
		int next = adj[start][i];
		if (pre[next] == 0)
		{
			pre[next] = start;
			dfs(next);
		}
	}
}
int main()
{
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	pre[1] = 1;
	dfs(1);
	for (int i = 2; i <= N; i++)
		cout << pre[i] << '\n';
	return 0;
}
/*
parent 배열이 사실상 방문 여부를 나타내는 역할을 합니다. 
parent[next]가 0이 아닌 값으로 설정되면, 노드 next가 방문되었고 그 부모가 할당되었음을 나타냅니다.
*/

int main()
{
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	for (int i = 2; i <= N; i++)
		cout << pre[i] << '\n';
}