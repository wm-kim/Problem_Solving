#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
typedef long long ll;
using namespace std;
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
	ll merge(ll left, ll right) { return left + right; }
	ll init(int node, int left, int right)
	{
		if (left == right) return max_tree[node] = arr[left];
		int mid = (left + right) / 2;
		ll leftVal = init(node * 2, left, mid);
		ll rightVal = init(node * 2 + 1, mid + 1, right);
		return max_tree[node] = merge(leftVal, rightVal);
	}
	ll sum(int node, int start, int end, int left, int right)
	{
		if (left > end || right < start) return 0;
		if (left <= start && end <= right) return max_tree[node];
		int mid = (start + end) / 2;
		ll leftVal = sum(node * 2, start, mid, left, right);
		ll rightVal = sum(node * 2 + 1, mid + 1, end, left, right);
		return merge(leftVal, rightVal);
	}
	ll update(int node, int start, int end, int index, ll newVal)
	{
		if (index < start || index > end) return max_tree[node];
		if (start == end) return max_tree[node] = newVal;
		int mid = (start + end) / 2;
		ll leftVal = update(node * 2, start, mid, index, newVal);
		ll rightVal = update(node * 2 + 1, mid + 1, end, index, newVal);
		return max_tree[node] = merge(leftVal, rightVal);
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
		else cout << st.sum(1, 1, N, b, c) << "\n";
	}
}