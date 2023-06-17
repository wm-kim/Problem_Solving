#include <iostream>
#include <vector>
#include <string>
using namespace std;
string compress(const vector<string>& image, int x, int y, int size) {
    char color = image[y][x];
    bool able = true;
    for (int i = y; i < y + size && able; ++i) {
        for (int j = x; j < x + size; ++j) {
            if (image[i][j] != color) {
                able = false;
                break;
            }
        }
    }
    if (able) return string(1, color);
    else {
        int n = size / 2;
        return "(" + compress(image, x, y, n) +
            compress(image, x + n, y, n) +
            compress(image, x, y + n, n) +
            compress(image, x + n, y + n, n) + ")";
    }
}
int main() {
    int N; cin >> N;
    vector<string> image(N); for (int i = 0; i < N; ++i) cin >> image[i];
    string result = compress(image, 0, 0, N);
    cout << result;
}