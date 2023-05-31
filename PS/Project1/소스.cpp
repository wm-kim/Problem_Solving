#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, u, v;
vector<int> graph[1000001];
int main()
{
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
}