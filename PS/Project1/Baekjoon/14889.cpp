#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N; int s[20][20];
vector<int> start, link;
int m = 1000000;

void bt(int d)
{
	if (d == N)
	{
		if ((int)start.size() != N / 2 || (int)link.size() != N / 2)
			return;

		int sum_start = 0, sum_link = 0;
		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < N / 2; j++) {
				if (i == j) continue;
				sum_start += s[start[i]][start[j]];
				sum_link += s[link[i]][link[j]];
			}
		}
		m = min(m, abs(sum_start - sum_link));
		return;
	}

	start.push_back(d); bt(d + 1); start.pop_back();
	link.push_back(d); bt(d + 1); link.pop_back();
}

int main()
{
	cin >> N; 
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			cin >> s[i][j];
	bt(0); 
	cout << m << "\n";
}