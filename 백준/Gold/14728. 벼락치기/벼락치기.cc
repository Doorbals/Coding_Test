#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
typedef pair<int, int> pii;
int dp[101][10001];
vector<pii> tests;
int n, t;

int solution()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= t; j++)
		{
			if (tests[i].first > j)
				dp[i][j] = dp[i - 1][j];
			else
			{
				dp[i][j] = max(dp[i - 1][j - tests[i].first] + tests[i].second, dp[i - 1][j]);
			}
		}
	}
	return dp[n][t];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> t;

	tests.push_back(pii(0, 0));
	for (int i = 0; i < n; i++)
	{
		int k, s;
		cin >> k >> s;
		tests.push_back(pii(k, s));
	}
	cout << solution();
}