#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#define MAX 10001
using namespace std;
int id, d[MAX]; // d : 각 node마다 고유한 번호 할당
bool finished[MAX];
vector<int> a[MAX];
vector<vector<int>> SCC;
stack<int> s;
int dfs(int x)
{
	d[x] = ++id; // 노드마다 고유한 번호 할당
	s.push(x); // 스택에 자기 자신을 삽입
	
	int parent = d[x];
	for (int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];
		// 방문하지 않은 이웃
		if (d[y] == 0) parent = min(parent, dfs(y));
		// 처리중인 이웃, 처리가 되고 있는 node에 다시 dfs를 수행할 수 없음.
		else if (!finished[y]) parent = min(parent, d[y]);
	}

	// 부모노드가 자기 자신인 경우
	if (parent == d[x])
	{
		vector<int> scc;
		while (1)
		{
			int t = s.top(); s.pop();
			scc.push_back(t);
			finished[t] = true;
			if (t == x) break;
		}
		SCC.push_back(scc);
	}
}
