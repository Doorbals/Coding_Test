#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<vector<int>> dp(10);

int solution()
{
	dp[1].push_back(1);
	dp[1].push_back(2);

	int count = 0;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < dp[i - 1].size(); j++)
		{
			for(int k = 0; k < 3; k++)
				dp[i].push_back(dp[i - 1][j] * 10 + k);
		}
	}

	for (int j = 0; j < dp[n].size(); j++)
	{
		if (dp[n][j] % 3 == 0)
			count++;
	}

	return count;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	cout << solution() << endl;
}