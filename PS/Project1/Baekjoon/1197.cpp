#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
const int INF = 2147483647;
using namespace std;
struct Edge { int to, w; };
int V, E, A, B, C; long long ans;
vector<Edge> adj[10001];
vector<int> mst;
int min_cost[10001], pre[10001];
bool inMST[10001];
void Prim()
{
	for (int i = 1; i <= V; i++) {
		min_cost[i] = INF; inMST[i] = false; pre[i] = -1;
	}
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, 1 });
	min_cost[1] = 0;
	while (!pq.empty())
	{
		int cur = pq.top().second; pq.pop();
		if (inMST[cur]) continue;
		inMST[cur] = true;
		if (pre[cur] != -1)
		{
			mst.push_back(pre[cur]);
			ans += min_cost[cur];
		}
		for (Edge& edge : adj[cur])
		{
			if (!inMST[edge.to] && min_cost[edge.to] > edge.w)
			{
				min_cost[edge.to] = edge.w;
				pre[edge.to] = cur;
				pq.push({ -edge.w, edge.to });
			}
		}
	}
	// or
	/*for (int i = 1; i <= V; i++) {
		ans += min_cost[i];
	}*/
}

int main()
{
	cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		cin >> A >> B >> C;
		adj[A].push_back({ B, C });
		adj[B].push_back({ A, C });
	}
	Prim();
	cout << ans << "\n";
}