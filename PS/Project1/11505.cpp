#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int N, M, K;
ll arr[1000001];
struct ST {
	int n, h;
	vector<ll> max_tree;
	ST(int _n) {
		n = _n;
		h = (int)ceil(log2(n));
		max_tree.resize(1 << (h + 1));
	}
	ll mul(ll left, ll right) { return (left * right) % MOD; }
	ll init(int node, int left, int right) {
		if (left == right) return max_tree[node] = arr[left];
		int mid = (left + right) / 2;
		ll leftVal = init(node * 2, left, mid);
		ll rightVal = init(node * 2 + 1, mid + 1, right);
		return max_tree[node] = mul(leftVal, rightVal);
	}
	ll query_max(int node, int start, int end, int left, int right) {
		if (left > end || right < start) return 1;
		if (left <= start && end <= right) return max_tree[node];
		int mid = (start + end) / 2;
		ll leftVal = query_max(node * 2, start, mid, left, right);
		ll rightVal = query_max(node * 2 + 1, mid + 1, end, left, right);
		return mul(leftVal, rightVal);
	}
	ll update(int node, int start, int end, int index, ll newval)
	{
		if (index < start || index > end) return max_tree[node];
		if (start == end) return max_tree[node] = newval;
		int mid = (start + end) / 2;
		ll leftVal = update(node * 2, start, mid, index, newval);
		ll rightVal = update(node * 2 + 1, mid + 1, end, index, newval);
		return max_tree[node] = mul(leftVal, rightVal);
	}
};

int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	ST st(N);
	st.init(1, 1, N);
	for (int i = 0; i < M + K; i++)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1) st.update(1, 1, N, b, c);
		else cout << st.query_max(1, 1, N, b, c) << "\n";
	}
}