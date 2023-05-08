#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Point {
    int x, y;
    bool operator<(const Point& other) const {
        if (y == other.y) return x < other.x;
        else return y < other.y;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;
    sort(points.begin(), points.end());
    for (int i = 0; i < n; i++) 
        cout << points[i].x << " " << points[i].y << "\n";
}