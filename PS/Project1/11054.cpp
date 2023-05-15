#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n; vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];

    vector<int> incDp(n, 1);
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (v[i] > v[j]) incDp[i] = max(incDp[i], incDp[j] + 1);

    vector<int> decDp(n, 1);
    for (int i = n - 2; i >= 0; i--)
        for (int j = n - 1; j > i; j--)
            if (v[i] > v[j]) decDp[i] = max(decDp[i], decDp[j] + 1);

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, incDp[i] + decDp[i] - 1);

    cout << ans << endl;
}