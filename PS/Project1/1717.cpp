#if 0
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
struct Node { int data; Node* parent; int rank; Node(int data) : data(data), parent(this), rank(0) {} };
Node* MakeSet(int data) { return new Node(data); }
Node* FindSet(Node* node) {
	if (node->parent == node) return node;
	return node->parent = FindSet(node->parent);
}
void Union(Node* node1, Node* node2) {
	Node* root1 = FindSet(node1);
	Node* root2 = FindSet(node2);
	if (root1 == root2) return;
	if (root1->rank > root2->rank) root2->parent = root1;
	else {
		root1->parent = root2;
		if (root1->rank == root2->rank) root2->rank++;
	}
}
int main()
{
	cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> n >> m;
	vector<Node*> nodes(n + 1);
	for (int i = 0; i <= n; i++) nodes[i] = MakeSet(i);
	for (int i = 1; i <= m; i++) {
		int op, a, b; cin >> op >> a >> b;
		if (op == 0) Union(nodes[a], nodes[b]);
		else {
			if (FindSet(nodes[a]) == FindSet(nodes[b])) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}
#endif
// int parent[1000001]; 로 풀어도됨

#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1000001;
int n, m;
int pnt[MAX], rnk[MAX];
int FindSet(int node) {
    if (pnt[node] == node) return node;
    return pnt[node] = FindSet(pnt[node]);
}
void Union(int node1, int node2) {
    int root1 = FindSet(node1);
    int root2 = FindSet(node2);
    if (root1 == root2)  return;
    if (rnk[root1] > rnk[root2]) pnt[root2] = root1;
    else {
        pnt[root1] = root2;
        if (rnk[root1] == rnk[root2]) rnk[root2]++;
    }
}
int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        pnt[i] = i; rnk[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 0) Union(a, b);
        else {
            if (FindSet(a) == FindSet(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
