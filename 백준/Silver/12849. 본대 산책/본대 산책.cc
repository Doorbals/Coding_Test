#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long dp[8][100001];			
const long long MOD = 1000000007;
int n;

long long solution()
{
	dp[0][0] = 1;

	for (int i = 1; i <= n; i++)
	{
		dp[0][i] = (dp[1][i - 1] + dp[2][i - 1]) % MOD;
		dp[1][i] = (dp[0][i - 1] + dp[2][i - 1] + dp[3][i - 1]) % MOD;
		dp[2][i] = (dp[0][i - 1] + dp[1][i - 1] + dp[3][i - 1] + dp[4][i - 1]) % MOD;
		dp[3][i] = (dp[1][i - 1] + dp[2][i - 1] + dp[4][i - 1] + dp[5][i - 1]) % MOD;
		dp[4][i] = (dp[2][i - 1] + dp[3][i - 1] + dp[5][i - 1] + dp[7][i - 1]) % MOD;
		dp[5][i] = (dp[3][i - 1] + dp[4][i - 1] + dp[6][i - 1]) % MOD;
		dp[6][i] = (dp[5][i - 1] + dp[7][i - 1]) % MOD;
		dp[7][i] = (dp[4][i - 1] + dp[6][i - 1]) % MOD;
	}
	return dp[0][n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	cout << solution();
}