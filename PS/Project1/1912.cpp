#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n; cin >> n; vector<int> sequence(n);
    for (int i = 0; i < n; i++) cin >> sequence[i];
    int maxSum = sequence[0]; int temp = sequence[0];
    for (int i = 1; i < n; i++) {
        if (temp < 0)  temp = sequence[i];
        else temp += sequence[i];
        maxSum = max(maxSum, temp);
    }
    cout << maxSum << endl;
}