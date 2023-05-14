#include <iostream>
#include <vector>
using namespace std;
int main()
{
	// �� ��ġ������ LIS ���̸� �����ϴ� �迭
	int n; cin >> n; vector<int> v(n + 1); vector<int> dp(n+1, 1);
	for (int i = 1; i <= n; i++) { cin >> v[i]; }
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < i; j++)
			// ���� ��� A[i]�� ���� ��� A[j]���� ũ��,
			// A[j]�� �������� �ϴ� LIS ����(dp[j])�� 1�� ���� ��(dp[j] + 1)��
			// A[i]�� �������� �ϴ� LIS ����(dp[i])���� ū ���
			if (v[i] > v[j]) { dp[i] = max(dp[i], dp[j] + 1); } // LIS ���̸� ����
	int ans = 0;
	for (int i = 1; i <= n; i++) { ans = ans > dp[i] ? ans : dp[i]; }
	cout << ans;
}