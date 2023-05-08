#include <iostream>
#include <vector>
using namespace std;
vector<bool> prime(246913, true);
void eratosthenes()
{
    prime[0] = prime[1] = false;
    for (int i = 2; i <= 123456; i++) 
    { 
        if (prime[i]) 
        { 
            for (int j = i * 2; j <= 246912; j += i) prime[j] = false;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    eratosthenes();
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        int count = 0;
        for (int i = n + 1; i <= 2 * n; i++)
            if (prime[i]) count++;
        cout << count << "\n";
    }
}