#if 1
#include <iostream>
#include <queue>
#include <vector>
#include <cstring> 
using namespace std;
const int MAX = 1001;
const int INF = 1000000;
int n, m, start, finish;
struct Bus { int to, cost; };
vector<Bus> city[MAX];
int dist[MAX], pre[MAX];

void Dijkstra(int start)
{
    memset(dist, INF, sizeof(dist));
    dist[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({ 0, start });
    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (dist[cur] < cost) continue;
        for (auto& next : city[cur])
        {
            if (dist[next.to] > dist[cur] + next.cost)
            {
                dist[next.to] = dist[cur] + next.cost;
                pq.push({ -dist[next.to], next.to });
                pre[next.to] = cur;
            }
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        city[from].push_back({ to, cost });
    }
    cin >> start >> finish;
    Dijkstra(start);
    cout << dist[finish] << "\n";
    int cur = finish, cnt = 0;
    vector<int> ans;
    while (cur != start)
    {
        ans.push_back(cur);
        cur = pre[cur];
    }
    ans.push_back(start);
    cout << ans.size() << "\n";
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << " ";
}
#endif