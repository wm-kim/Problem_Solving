#if 0
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
int N, K;
class TrieNode {
public:
	map<string, TrieNode*> children;
	bool isEnd;
	string value;
	TrieNode(string value = "") : isEnd(false), value(value) {}
};
class Trie {
private:
	TrieNode* root;
	void dfs(TrieNode* cur, int depth)
	{
		if (cur != root)
		{
			for (int i = 0; i < depth - 1; i++) cout << "--";
			cout << cur->value << "\n";
		}
		if (cur->isEnd) return;
		for (auto child : cur->children) dfs(child.second, depth + 1);
	}
public:
	Trie() { root = new TrieNode(); }
	void insert(vector<string>& words)
	{
		TrieNode* cur = root;
		for (const string& word : words)
		{
			if (cur->children.find(word) == cur->children.end())
				cur->children[word] = new TrieNode(word);
			cur = cur->children[word];
		}
		cur->isEnd = true;
	}
	void print() { dfs(root, 0); }
};
int main()
{
	cin.tie(0); ios::sync_with_stdio(false);
	Trie trie;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> K;
		vector<string> v(K);
		for (int j = 0; j < K; j++) cin >> v[j];
		trie.insert(v);
	}
	trie.print();
}
#endif