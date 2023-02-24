#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>
using namespace std;

int n;
int dp[1001][3];	// dp[i][j] : i번째 집에서 j색으로 칠했을 때의 최소 비용
vector<vector<int>> costs;

void solution()
{
	for (int i = 0; i < 3; i++)
		dp[1][i] = costs[1][i];

	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2];
	}

	cout << min({ dp[n][0], dp[n][1], dp[n][2] });
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	costs.resize(n + 1);

	for (int i = 0; i < n; i++)
		costs[0].push_back(0);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int cost;
			cin >> cost;
			costs[i].push_back(cost);
		}
	}
	solution();
}