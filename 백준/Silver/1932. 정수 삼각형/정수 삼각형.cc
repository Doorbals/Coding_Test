#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>
using namespace std;

int n;
int dp[501][501];
vector<vector<int>> nums;

void solution()
{
	dp[1][0] = nums[1][0];

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < nums[i].size(); j++)
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][j] + nums[i][j];
			else if (j == nums[i].size() - 1)
				dp[i][j] = dp[i - 1][j - 1] + nums[i][j];
			else
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + nums[i][j];
		}
	}

	int maxValue = 0;
	for (int i = 0; i < n; i++)
		maxValue = max(maxValue, dp[n][i]);

	cout << maxValue;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	nums.resize(n + 1);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			int num;
			cin >> num;
			nums[i].push_back(num);
		}
	}
	solution();
}