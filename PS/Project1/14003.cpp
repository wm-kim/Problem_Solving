#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int N; cin >> N;
    vector<int> nums, v, indices, ans;
	v.push_back(1000000000);
    for (int i = 0; i < N; i++) {
		int num; cin >> num; nums.push_back(num);
        if (num > v.back())
        {
            v.push_back(num);
			indices.push_back(v.size() - 1);
        }
        else {
            int idx = lower_bound(v.begin(), v.end(), num) - v.begin();
            v[idx] = num;
			indices.push_back(idx);
        }
    }
	cout << v.size() << "\n";
	int idx = v.size() - 1;
	for (int i = indices.size() - 1; i >= 0; i--)
	{
		if (indices[i] == idx)
		{
			ans.push_back(i);
			idx--;
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--) cout << nums[ans[i]] << " ";
}
// O(NlogN) LIS를 출력하는 문제
// idea : 배열을 하나 더 만들어 줘서 현재 원소가 증가하는 부분수열의 몇 번째에 들어갈 수 있는 원소인지 표시
// 새로 만든 배열의 뒷 부분부터 앞으로 탐색을 하면서 i번째(N-1부터 0까지) 원소를 stack에 넣어준다.