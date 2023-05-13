#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin >> n;
    int mem[1001][3] = { 0 };
    for (int i = 1; i <= n; i++)
    {
        int r, g, b; cin >> r >> g >> b;
        mem[i][0] = min(mem[i - 1][1], mem[i - 1][2]) + r;
        mem[i][1] = min(mem[i - 1][0], mem[i - 1][2]) + g;
        mem[i][2] = min(mem[i - 1][0], mem[i - 1][1]) + b;
    }
    cout << min(mem[n][0], min(mem[n][1], mem[n][2])) << endl;
}