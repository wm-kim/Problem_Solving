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

// 시간 초과
/*
1. 주어진 입력을 algorithm의 sort 함수를 활용하여 정렬을 해주었다.
2.  for문을 통해 정렬한 함수를 순회하며 vector<pair<int, int>>에 쌍을 지어 first는 등장한 숫자, 
    second는 숫자가 등장한 횟수를 담아주었다.
	// 배열을 생성해, '같은 숫자의 가장 오른쪽 위치'에 숫자의 개수가 저장되게 끔 for문을 돌린다
3. 이렇게 정렬한 vector에서 이분 탐색을 시행하였다.
*/

/*
Algorithm STL의 upper_bound, lower_bound을 사용한 풀이
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