#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
vector<int> graph[100001]; int pnt[100001];
void dfs(int start)
{
	for (int i = 0; i < graph[start].size(); i++)
	{
		int next = graph[start][i];
		if (pnt[next] == 0)
		{
			pnt[next] = start;
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
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	pnt[1] = 1;
	dfs(1);
	for (int i = 2; i <= N; i++)
		cout << pnt[i] << '\n';
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
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1);
	for (int i = 2; i <= N; i++)
		cout << pnt[i] << '\n';
}