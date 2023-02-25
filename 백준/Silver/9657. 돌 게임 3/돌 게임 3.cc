#include <iostream>
using namespace std;

bool dp[1001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 0;
	dp[3] = 1;
	dp[4] = 1;

	for (int i = 5; i <= n; i++)
	{
		if (!dp[i - 1] || !dp[i - 3] || !dp[i - 4])
			dp[i] = 1;
		else
			dp[i] = 0;
	}
	
	if (dp[n])
		cout << "SK";
	else
		cout << "CY";
}