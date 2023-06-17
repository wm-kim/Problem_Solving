#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
struct TrieNode {
public:
	unordered_map<char, TrieNode*> children;
	bool isEnd;
	TrieNode() : isEnd(false) {}

	void insert(const string& word) {
		TrieNode* cur = this;
		for (const char& c : word) {
			if (cur->children.find(c) == cur->children.end()) 
				cur->children[c] = new TrieNode();
			cur = cur->children[c];
		}
		cur->isEnd = true;
	}

	int cntPress(const string& word) {
		int cnt = 0;
		TrieNode* cur = this;
		for (int i = 0; i < word.size(); i++) {
			if (cur->children.size() > 1 || cur->isEnd || i == 0) cnt++;
			cur = cur->children[word[i]];
		}
		return cnt;
	}
};
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	int N;
	while (cin >> N)
	{
		TrieNode root;
		vector<string> v(N);
		for (int i = 0; i < N; i++) { cin >> v[i]; root.insert(v[i]); }
		double sum = 0;
		for (int i = 0; i < N; i++) { sum += root.cntPress(v[i]); }
		double ans = sum / N;
		cout.precision(2);
		cout << fixed << ans << "\n";
	}
}