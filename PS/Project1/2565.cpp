#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Wire { int a; int b; };
bool comp(const Wire& wire1, const Wire& wire2) {
    return wire1.a < wire2.a;
}
int main() {
    int n; cin >> n;
    vector<Wire> wires(n);
    for (int i = 0; i < n; i++) {
        cin >> wires[i].a >> wires[i].b;
    }
    sort(wires.begin(), wires.end(), comp);
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            if (wires[i].b > wires[j].b) dp[i] = max(dp[i], dp[j] + 1);
    }
    int maxLIS = 0;
    for (int i = 0; i < n; i++) maxLIS = max(maxLIS, dp[i]);
    cout << n - maxLIS << endl;
}