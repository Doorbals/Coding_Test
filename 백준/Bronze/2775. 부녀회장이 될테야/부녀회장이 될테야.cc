#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>

using namespace std;
int dp[15][15];

int solution(int k, int n)
{
	for (int i = 1; i <= n; i++)
		dp[0][i] = i;

	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= j; k++)
				dp[i][j] += dp[i - 1][k];
		}
	}

	return dp[k][n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int k, n;
		cin >> k >> n;
		cout << solution(k, n) << endl;


		for (int i = 0; i <= k; i++)
		{
			for (int j = 0; j <= n; j++)
				dp[i][j] = 0;
		}
	}
}