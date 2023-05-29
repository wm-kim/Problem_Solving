#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
int T, F;
struct Friend { 
	string name; int rank; int size; 
	Friend() : rank(0), size(1) {}
	Friend(string name) : name(name), rank(0), size(1) {} 
};
map<string, Friend> mp;
map<string, string> parent;
Friend& makeFriend(string name) 
{ 
	Friend& newFriend = mp[name] = Friend(name);
	parent[name] = name;
	return newFriend;
}
Friend* find(string s)
{
	if (parent[s] == s) return &mp[s];
	else return find(parent[s]);
}
void merge(string x, string y)
{
	Friend* root1 = find(x); Friend* root2 = find(y);
	if (root1->name == root2->name) return;
	if (root1->rank > root2->rank) {
		parent[root2->name] = root1->name;
		root1->size += root2->size;
	}
	else {
		parent[root1->name] = root2->name;
		root2->size += root1->size;
		if (root1->rank == root2->rank) root2->rank++;
	}
}
int main()
{
	cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> T;
	while (T--)
	{
		cin >> F;
		for (int i = 0; i < F; i++)
		{
			string s1, s2; cin >> s1 >> s2; 
			if (mp.find(s1) == mp.end()) makeFriend(s1);
			if (mp.find(s2) == mp.end()) makeFriend(s2);
			merge(s1, s2);
			cout << find(s1)->size << "\n";
		}

		mp.clear();
		parent.clear();
	}
}