#if 0
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
struct Meeting { int start, end; };
bool Compare(const Meeting& a, const Meeting& b)
{
	if (a.start == b.start) return a.end < b.end;
	return a.start < b.start;
}
int main()
{
	int n; cin >> n; 
	vector<Meeting> v(n+1); for (int i = 1; i <= n; i++) { cin >> v[i].start >> v[i].end; }
	sort(v.begin(), v.end(), Compare);
	int ans = 0, endTime = v[n].end;
	for (int i = n; i >= 1; i--)
	{
		if (v[i].end <= endTime) 
		{ 
			ans++; endTime = v[i].start; 
		}
	}
	cout << ans << "\n";
}
#endif

/*
struct Meeting {
    int start, end;
};

bool compare(const Meeting& a, const Meeting& b) {
    if (a.end == b.end)
        return a.start < b.start;
    return a.end < b.end;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Meeting> meetings(n);
    for (int i = 0; i < n; ++i)
        std::cin >> meetings[i].start >> meetings[i].end;

    std::sort(meetings.begin(), meetings.end(), compare);

    int count = 1;
    int endTime = meetings[0].end;

    for (int i = 1; i < n; ++i) {
        if (meetings[i].start >= endTime) {
            ++count;
            endTime = meetings[i].end;
        }
    }

    std::cout << count << std::endl;

    return 0;
}

*/
#include "memory_tracker.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    int ans = 0, endTime = v[n - 1].second;
    for (int i = n - 1; i >= 0; i--)
        if (v[i].second <= endTime) { ans++; endTime = v[i].first;  }
    cout << ans << "\n";
}