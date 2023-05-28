#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int A, B;

struct Node
{
    int n, cnt; // node and count of movements
    string path; // path from start to this node
    Node(int nn, string p, int cc) : n(nn), cnt(cc), path(p) {}
};

string bfs(int start, int end)
{
    vector<bool> visited(10000, false);
    queue<Node> q;
    q.push(Node(start, "", 0));
    visited[start] = true;

    while (!q.empty())
    {
        Node cur = q.front(); q.pop();

        if (cur.n == end) return cur.path;

        int D = (cur.n * 2) % 10000;
        int S = (cur.n == 0) ? 9999 : cur.n - 1;
        int L = (cur.n % 1000) * 10 + (cur.n / 1000);
        int R = (cur.n % 10) * 1000 + (cur.n / 10);

        if (!visited[D]) { q.push(Node(D, cur.path + "D", cur.cnt + 1)); visited[D] = true; }
        if (!visited[S]) { q.push(Node(S, cur.path + "S", cur.cnt + 1)); visited[S] = true; }
        if (!visited[L]) { q.push(Node(L, cur.path + "L", cur.cnt + 1)); visited[L] = true; }
        if (!visited[R]) { q.push(Node(R, cur.path + "R", cur.cnt + 1)); visited[R] = true; }
    }
    return "";
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while (T--)
    {
        cin >> A >> B;
        string ans = bfs(A, B);
        cout << ans << "\n";
    }
}