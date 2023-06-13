#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define INT_MAX 1000000000
using namespace std;
int N, M, arr[100001];
struct ST {
	int n, h;
	vector<int> max_tree, min_tree;
	ST(int _n) {
		n = _n;
		h = (int)ceil(log2(n));
		max_tree.resize(1 << (h + 1));
		min_tree.resize(1 << (h + 1));
	}
	int init_max(int node, int left, int right) {
		if (left == right) return max_tree[node] = arr[left];
		int mid = (left + right) / 2;
		return max_tree[node] = max(init_max(node * 2, left, mid), init_max(node * 2 + 1, mid + 1, right));
	}
	int init_min(int node, int left, int right) {
		if (left == right) return min_tree[node] = arr[left];
		int mid = (left + right) / 2;
		return min_tree[node] = min(init_min(node * 2, left, mid), init_min(node * 2 + 1, mid + 1, right));
	}
	int query_max(int node, int start, int end, int left, int right) {
		if (left > end || right < start) return 1;
		if (left <= start && end <= right) return max_tree[node];
		int mid = (start + end) / 2;
		return max(query_max(node * 2, start, mid, left, right), query_max(node * 2 + 1, mid + 1, end, left, right));
	}
	int query_min(int node, int start, int end, int left, int right)
	{
		if (left > end || right < start) return INT_MAX;
		if (left <= start && end <= right) return min_tree[node];
		int mid = (start + end) / 2;
		return min(query_min(node * 2, start, mid, left, right), query_min(node * 2 + 1, mid + 1, end, left, right));
	}
};
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	ST st(N);
	st.init_max(1, 1, N); st.init_min(1, 1, N);
	for (int i = 0; i < M; i++) 
	{ 
		int a, b; cin >> a >> b; 
		cout << st.query_min(1, 1, N, a, b) << " " << st.query_max(1, 1, N, a, b) << "\n";
	}
}