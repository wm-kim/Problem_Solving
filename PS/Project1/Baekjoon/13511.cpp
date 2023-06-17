#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
vector<p> g[101010];
ll dp[101010][22];
ll dist[101010];
ll dep[101010];
ll n;
bool chk[101010];
void dfs(ll now, ll d, ll c) {
	chk[now] = 1;
	dep[now] = d;
	dist[now] = c;
	for (auto i : g[now]) {
		ll nxt = i.first;
		if (chk[nxt]) continue;
		ll nxtCost = i.second + c;
		dp[nxt][0] = now;
		dfs(nxt, d + 1, nxtCost);
	}
}
void make() {
	for (int j = 1; j < 22; j++) {
		for (int i = 1; i <= n; i++) {
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
		}
	}
}
ll getLca(ll u, ll v) {
	if (dep[u] > dep[v]) swap(u, v);
	ll diff = dep[v] - dep[u];
	for (int i = 0; diff; i++) {
		if (diff & 1) v = dp[v][i];
		diff >>= 1;
	}
	if (u == v) return u;
	for (int i = 21; i >= 0; i--) {
		if (dp[u][i] != dp[v][i]) u = dp[u][i], v = dp[v][i];
	}
	return dp[u][0];
}
ll getDist(ll u, ll v) {
	ll lca = getLca(u, v);
	return dist[u] + dist[v] - 2 * dist[lca];
}
ll getkth(ll u, ll v, ll k) {
	ll lca = getLca(u, v);
	ll diff = dep[u] - dep[lca];
	k--;
	if (diff >= k) {
		for (int i = 0; k; i++) {
			if (k & 1) u = dp[u][i];
			k >>= 1;
		}
		return u;
	}
	k = dep[v] - dep[lca] + diff - k;
	for (int i = 0; k; i++) {
		if (k & 1) v = dp[v][i];
		k >>= 1;
	}
	return v;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		ll s, e, x; cin >> s >> e >> x;
		g[s].push_back({ e, x });
		g[e].push_back({ s, x });
	}
	dfs(1, 1, 0); make();
	int m; cin >> m;
	while (m--) {
		int op; cin >> op;
		if (op == 1) {
			ll a, b; cin >> a >> b;
			cout << getDist(a, b) << "\n";
		}
		else {
			ll a, b, c; cin >> a >> b >> c;
			cout << getkth(a, b, c) << "\n";

		}
	}
}

#if 0
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n, m, len;
vector<vector<pair<int, int>>> adj;   //to, weight

//for LCA
int depth[100001], parent[100001][17];
long long cost[100001][17];

pair<int, long long > LCA(int u, int v) {

	long long ret = 0;

	if (depth[u] < depth[v])
		swap(u, v);

	int diff = depth[u] - depth[v];

	for (int k = 0; diff != 0; ++k) {

		if (diff % 2 == 1) {
			ret += cost[u][k];
			u = parent[u][k];
		}
		diff /= 2;
	}


	if (u != v) {

		for (int k = len - 1; k >= 0; --k) {
			if (parent[u][k] != parent[v][k]) {
				ret += cost[u][k] + cost[v][k];
				u = parent[u][k];
				v = parent[v][k];
			}
		}
		ret += cost[u][0] + cost[v][0];
		u = parent[u][0];
	}

	return { u,ret };
}

void dfs(int cur, int before)
{
	for (pair<int, long long> next : adj[cur])
	{
		if (next.first == before)
			continue;

		parent[next.first][0] = cur;
		cost[next.first][0] = next.second;
		depth[next.first] = depth[cur] + 1;
		dfs(next.first, cur);
	}
	return;
}


int main()
{
	scanf("%d", &n);
	adj.resize(n + 1);
	len = (int)ceil(log2(n));

	for (int i = 0; i < n - 1; ++i) {
		int from, to, weight;

		scanf("%d %d %d", &from, &to, &weight);

		adj[from].push_back({ to,weight });
		adj[to].push_back({ from,weight });
	}

	dfs(1, 0);   //root is a 'vertex 1'

	for (int k = 0; k < len - 1; ++k)
		for (int i = 1; i <= n; ++i) {
			parent[i][k + 1] = parent[parent[i][k]][k];
			cost[i][k + 1] = cost[parent[i][k]][k] + cost[i][k];
		}


	scanf("%d", &m);
	while (m--)
	{
		int sel;
		scanf("%d", &sel);

		if (sel == 1) {
			int from, to;
			scanf("%d %d", &from, &to);

			pair<int, long long> ret = LCA(from, to);

			printf("%lld\n", ret.second);


		}
		else
		{
			int from, to, k;
			scanf("%d %d %d", &from, &to, &k);

			pair<int, long long> ret = LCA(from, to);

			if (depth[from] - depth[ret.first] + 1 >= k) {

				int diff = k - 1;
				int cur = from;

				for (int i = 0; diff != 0; ++i) {
					if (diff % 2 == 1) {
						cur = parent[cur][i];
					}
					diff = diff >> 1;
				}

				printf("%d\n", cur);
			}
			else
			{
				k = k - (depth[from] - depth[ret.first]);

				int diff = depth[to] - depth[ret.first] + 1 - k;
				int cur = to;

				for (int i = 0; diff != 0; ++i) {
					if (diff % 2 == 1) {
						cur = parent[cur][i];
					}
					diff = diff >> 1;
				}

				printf("%d\n", cur);
			}

		}
	}
	return 0;
}
#endif