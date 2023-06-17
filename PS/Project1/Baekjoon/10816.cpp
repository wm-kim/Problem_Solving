#if 0
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	int n; cin >> n; map<int, int> mp;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		mp[x]++;
	}
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		if (mp.find(x) != mp.end()) cout << mp[x] << " ";
		else cout << 0 << " ";
	}
}
#endif

// binary search
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void binarySearch(vector<int>& v, int left, int right, int num, int& cnt) {
	if (left > right) return;
	int mid = (left + right) / 2;
	if (v[mid] == num) cnt++;
	binarySearch(v, mid + 1, right, num, cnt);
	binarySearch(v, left, mid - 1, num, cnt);
}
int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	int n; cin >> n; vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	int m; cin >> m;
	while (m--)
	{
		int num; cin >> num;
		int cnt = 0; binarySearch(v, 0, n - 1, num, cnt);
		cout << cnt << ' ';
	}
} 

// �ð� �ʰ�
/*
1. �־��� �Է��� algorithm�� sort �Լ��� Ȱ���Ͽ� ������ ���־���.
2.  for���� ���� ������ �Լ��� ��ȸ�ϸ� vector<pair<int, int>>�� ���� ���� first�� ������ ����, 
    second�� ���ڰ� ������ Ƚ���� ����־���.
	// �迭�� ������, '���� ������ ���� ������ ��ġ'�� ������ ������ ����ǰ� �� for���� ������
3. �̷��� ������ vector���� �̺� Ž���� �����Ͽ���.
*/

/*
Algorithm STL�� upper_bound, lower_bound�� ����� Ǯ��
#include <iostream>
#include <algorithm>
using namespace std;
int arr[500002];
int N, M, card;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> card;
		arr[i] = card;
	}
	sort(arr, arr + N); 
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> card;
		cout << upper_bound(arr, arr + N, card) - lower_bound(arr, arr + N, card)<<" ";
	}
}
*/