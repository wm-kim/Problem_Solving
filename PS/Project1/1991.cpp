#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Node { char data; Node* left; Node* right; };
void preorder(Node* root) {
	if (root == NULL) return;
	cout << root->data;
	preorder(root->left);
	preorder(root->right);
}
void inorder(Node* root) {
	if (root == NULL) return;
	inorder(root->left);
	cout << root->data;
	inorder(root->right);
}
void postorder(Node* root) {
	if (root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data;
}
int main()
{
	int N; cin >> N;
	vector<Node> tree(26); 
	for (int i = 0; i < N; i++) {
		char data, left, right; cin >> data >> left >> right;
		tree[data - 'A'].data = data;
		if (left != '.') tree[data - 'A'].left = &tree[left - 'A'];
		if (right != '.') tree[data - 'A'].right = &tree[right - 'A'];
	}
	Node* root = &tree[0];
	preorder(root); cout << "\n";
	inorder(root); cout << "\n";
	postorder(root); cout << "\n";
}