#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>

using namespace std;
typedef pair<int, int> pii;

int dp[1001][10001];
vector<pii> subjects;	// 각 과목의 (중요도, 공부 시간) 저장
int n, k;

int solution()
{
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (subjects[i].second > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j - subjects[i].second] + subjects[i].first, dp[i - 1][j]);
		}
	}
	return dp[k][n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> k;
	
	subjects.push_back(pii(0, 0));
	for (int i = 0; i < k; i++)
	{
		int v, t;
		cin >> v >> t;
		subjects.push_back(pii(v, t));
	}
	cout << solution();
}