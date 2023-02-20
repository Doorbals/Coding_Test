#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int dp[16][16];
int dp2[16][16];
int n, m, k;

int solution()
{
	for (int i = 0; i < m; i++)
		dp[0][i] = 1;

	for (int i = 0; i < n; i++)
		dp[i][0] = 1;

	if (k == 0)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp[n - 1][m - 1];
	}
	else
	{
		int stopOverY = k / m, stopOverX = k % m - 1;

		for (int i = 1; i <= stopOverY; i++)
		{
			for (int j = 1; j <= stopOverX; j++)
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}

		for (int i = stopOverX; i < m; i++)
			dp2[stopOverY][i] = 1;

		for (int i = stopOverY; i < n; i++)
			dp2[i][stopOverX] = 1;

		for (int i = stopOverY + 1; i < n; i++)
		{
			for (int j = stopOverX + 1; j < m; j++)
			{
				dp2[i][j] = dp2[i - 1][j] + dp2[i][j - 1];
			}
		}
		return dp[stopOverY][stopOverX] * dp2[n - 1][m - 1];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m >> k;
	cout << solution();
}