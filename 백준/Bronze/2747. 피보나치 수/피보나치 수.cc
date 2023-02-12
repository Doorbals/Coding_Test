#include <iostream>
using namespace std;
int dp[46];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i <= n; i++)
	{
		if (i == 0)
			dp[i] = 0;
		else if (i == 1)
			dp[i] = 1;
		else
			dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n];
}