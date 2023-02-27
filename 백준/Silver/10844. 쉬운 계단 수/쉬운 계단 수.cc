#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long dp[101][10];
const long long MOD = 1000000000;

long long solution() 
{
	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;
	
	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][1] % MOD;
		for (int j = 1; j <= 8; j++)
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
		dp[i][9] = dp[i - 1][8] % MOD;
	}
		
	long long maxValue = 0;
	for (int i = 0; i <= 9; i++)
		maxValue = (maxValue + dp[n][i]) % MOD;
	
	return maxValue;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	cout << solution();
}