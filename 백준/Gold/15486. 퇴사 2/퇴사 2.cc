#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>

using namespace std;
typedef pair<int, int> pii;
int dp[1500051];
pii consultings[1500051];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		consultings[i] = pii(a, b);
	}

	for (int i = 1; i <= n + 1; i++)
	{
		dp[i] = max(dp[i], dp[i - 1]);
		dp[i + consultings[i].first] = max(dp[i + consultings[i].first], dp[i] + consultings[i].second);
	}

	cout << dp[n + 1] << ' ';
		
}