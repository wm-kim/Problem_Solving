#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    vector<int> v = { 1000000 };
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a > v.back()) v.push_back(a);
        else {
            int idx = lower_bound(v.begin(), v.end(), a) - v.begin();
            v[idx] = a;
        }
    }
    cout << v.size();
}