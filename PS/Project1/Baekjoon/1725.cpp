#if 0
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
	int N; cin >> N;
	vector<int> v(N); for (int i = 0; i < N; i++) cin >> v[i];
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		stack<int> s; s.push(v[i]); int maxArea = v[i];
		for (int j = i + 1; j < N; j++)
		{
			if (!s.empty() && s.top() >= v[j])
			{
				if (maxArea > (j - i + 1) * v[j]) break;
				else maxArea = (j - i + 1) * v[j];
			}
		}
		if (ans < maxArea) ans = maxArea;
	}
	cout << ans << "\n";
}
#endif

/* 아이디어 

1. O(N^2) 모든 elemnt에대해 left smaller index, right smaller index 찾기

2. 막대의 인덱스를 순서대로 스택에 push 할 때 
push 하려는 막대의 높이가 stack.top height 보다 크거나 같다면 계속해서 스택을 쌓습니다.
만약에 반대로 작을 경우, stack.top height가 push 하려는 막대의 높이보다 작아질 때까지 while문을 도는데,
while문 안에서는 스택을 하나씩 pop 하면서 구할 수 있는 직사각형의 최대 넓이를 구하게 됩니다.
*/

#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
int N, ans, h[100002];
stack<int> s;
int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> h[i];
	s.push(0); // 스택이 비어있는 스택의 top을 확인할 경우 오류를 위해서 스택에 0을 먼저 push 합니다.
	for (int i = 1; i <= N + 1; i++)
	{
		// 스택이 비어 있지 않고, 
		// 스택의 가장 위에 있는 직사각형의 높이가 현재 직사각형의 높이보다 큰 경우에는 아래의 과정을 수행
		while (!s.empty() && h[s.top()] > h[i])
		{
			// 스택 가장 위에 있는 직사각형을 check에 저장하고 stack에서 제거
			int check = s.top(); s.pop();
			// 직사각형의 넓이는 높이(h[check])에 현재 인덱스(i)와 (s.top())의 차이를 곱한 값
			int area = h[check] * (i - s.top() - 1);
			ans = max(ans, area);
		}
		// push 하려는 막대의 높이가 stack.top height 보다 크거나 같다면 계속해서 스택을 쌓습니다.
		s.push(i);
	}
	cout << ans;
}

