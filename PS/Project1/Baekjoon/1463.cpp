#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n; cin >> n; vector<int> dp(n+1);
	for (int i = 2; i <= n; i++)
	{
		if (i == 2) dp[2] = 1;
		if (i % 3 == 0 && i % 2 == 0) dp[i] = min(dp[i / 3], min(dp[i / 2], dp[i - 1])) + 1;
		else if (i % 3 == 0) dp[i] = min(dp[i / 3], dp[i - 1]) + 1;
		else if (i % 2 == 0) dp[i] = min(dp[i / 2], dp[i - 1]) + 1;
		else dp[i] = dp[i - 1] + 1;
	}
	cout << dp[n];
}

/*
int main()
{
    int N;
    scanf("%d",&N);
    int dp[10000001];

    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for(int i=4; i<=N; i++)
    {
        dp[i] = dp[i-1] + 1;
        if(i%2==0) dp[i] = min(dp[i], dp[i/2]+1);
        if(i%3==0) dp[i] = min(dp[i],dp[i/3]+1);
    }
    printf("%d\n",dp[N]);
    return 0;
}
*/