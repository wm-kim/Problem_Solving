#include <iostream>
#include <algorithm>
#include <vector>
#define INF 2000000000
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end());
    int i = 0, j = N - 1, min = INF, ans_i, ans_j;
    while (i < j)
    {
		int sum = v[i] + v[j];
        if (abs(sum) < min)
        {
			min = abs(sum);
			ans_i = i;
			ans_j = j;
            
			// if (min == 0) break;
        }
        if (sum < 0) i++;
        else j--;
    }
    cout << v[ans_i] << " " << v[ans_j];
}