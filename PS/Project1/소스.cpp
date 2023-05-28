#include <iostream>
#include <algorithm>
#include <vector>
const int MAX = 100001;
using namespace std;
int N, inorder[MAX], postorder[MAX];
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) { cin >> inorder[i]; }
	for (int i = 0; i < N; i++) { cin >> postorder[i]; }
}

/*
분할 정복을 통해 풀이
*/