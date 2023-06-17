#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int grid[25][25];
bool dist[25][25] = { false };
int N, dx[] = { 0,0,-1,1 }, dy[] = { -1,1,0,0 };
vector<int> ans;
void dfs(int x, int y)
{
	dist[y][x] = true;
	ans.back()++;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && !dist[ny][nx] && grid[ny][nx])
			dfs(nx, ny);
	}
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s; cin >> s;
		for (int j = 0; j < N; j++) grid[i][j] = s[j] - '0';
	}
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			if (grid[i][j] == 1 && !dist[i][j]) { ans.push_back(0); dfs(j, i); }
	cout << ans.size() << "\n";
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << "\n";
}