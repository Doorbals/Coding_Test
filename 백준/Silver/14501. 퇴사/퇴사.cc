#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>

using namespace std;
typedef pair<int, int> pii;
int dp[16];
vector<pii> consultings;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	consultings.push_back(pii(0, 0));
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		consultings.push_back(pii(a, b));
	}

	for (int i = 1; i <= n + 1; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (i >= j + consultings[j].first)
			{
				dp[i] = max(dp[i], dp[j] + consultings[j].second);
			}
		}
	}

	cout << dp[n + 1];
}