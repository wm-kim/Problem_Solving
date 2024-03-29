#include <iostream>
#include <vector>
using namespace std;
int N, m;
vector<int> ans;
bool dist[9];

void backtracking(int depth)
{
	if (depth == m)
	{
		for (int i = 0; i < m; i++) cout << ans[i] << " ";
		cout << "\n"; return;
	}
	for (int i = 1; i <= N; i++)
	{
		if (!dist[i])
		{
			dist[i] = true; ans.push_back(i);
			backtracking(depth + 1);
			ans.pop_back(); dist[i] = false;
		}
	}
}

int main() {
	cin >> N >> m;
	backtracking(0);
}