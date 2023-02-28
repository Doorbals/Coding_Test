#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
vector<int> costs;
int dp[1001][1001];		// dp[i][j] : i 번째 카드팩까지 있을 때 j개의 카드를 사는 최대 금액

int solution() 
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			// 현재 순서의 카드팩으로 j개의 카드를 살 수 없을 때 (j개를 딱 맞출 수 없음) 
			if (i > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i][j - i] + costs[i], dp[i - 1][j]);
		}
	}
	return dp[n][n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	costs.push_back(0);
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		costs.push_back(num);
	}
	cout << solution();
}