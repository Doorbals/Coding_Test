#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>

using namespace std;
const int INF = 100001;
int dp[100001];
int units[101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i <= k; i++)
		dp[i] = INF;

	for (int i = 0; i < n; i++)
	{
		cin >> units[i];
		dp[units[i]] = 1;
	}

	for (int i = 1; i <= k; i++)
	{
		if (dp[i] == INF)
		{
			for (int j = 0; j < n; j++)
			{
				if (i - units[j] > 0)
					dp[i] = min(dp[i], dp[i - units[j]] + 1);
			}
		}
	}

	cout << ((dp[k] == INF) ? -1 : dp[k]);
}

	