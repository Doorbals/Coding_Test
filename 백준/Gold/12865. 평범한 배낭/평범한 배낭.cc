#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>

using namespace std;
typedef pair<int, int> pii;

vector<pii> stuffs;
int dp[101][100001];
int n, k;

int solution()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (stuffs[i].first > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j - stuffs[i].first] + stuffs[i].second, dp[i - 1][j]);
		}
	}
	return dp[n][k];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> k;

	stuffs.push_back(pii(0, 0));
	for (int i = 0; i < n; i++)
	{
		int w, v;
		cin >> w >> v;
		stuffs.push_back(pii(w, v));
	}
	cout << solution();
}