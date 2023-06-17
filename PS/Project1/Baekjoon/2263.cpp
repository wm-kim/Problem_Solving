#include <iostream>
#include <algorithm>
#include <vector>
const int MAX = 100001;
using namespace std;
int N, inorder[MAX], postorder[MAX], idx[MAX];
void GetPreOrder(int inStart, int inEnd, int postStart, int postEnd)
{
	if (inStart > inEnd || postStart > postEnd) return;
	int root = postorder[postEnd];
	int rootIdx = idx[root];
	int leftSize = rootIdx - inStart; int rightSize = inEnd - rootIdx;
	cout << root << " ";
	GetPreOrder(inStart, rootIdx - 1, postStart, postStart + leftSize - 1);
	GetPreOrder(rootIdx + 1, inEnd, postStart + leftSize, postEnd - 1);
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) { cin >> inorder[i]; idx[inorder[i]] = i; }
	for (int i = 1; i <= N; i++) { cin >> postorder[i]; }
	GetPreOrder(1, N, 1, N);
	cout << "\n";
}

/*
* 
* inorder의 index 저장 (ex 1은 inorder에서 6번째에 있음)
분할 정복을 통해 풀이
https://donggoolosori.github.io/2020/10/15/boj-2263/
*/