#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>
using namespace std;

int n;
long long dp[101];

long long solution() 
{
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;

	for (int i = 6; i <= n; i++)
		dp[i] = dp[i - 5] + dp[i - 1];

	return dp[n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		cout << solution() << endl;
	}
}