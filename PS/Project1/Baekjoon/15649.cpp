#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> ans;
bool visited[9];

void backtracking(int depth)
{
	if (depth == m)
	{
		for (int i = 0; i < m; i++) cout << ans[i] << " ";
		cout << "\n"; return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			visited[i] = true; ans.push_back(i);
			backtracking(depth + 1);
			ans.pop_back(); visited[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	backtracking(0);
}