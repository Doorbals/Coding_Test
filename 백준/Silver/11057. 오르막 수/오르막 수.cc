#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long dp[1001][10];		// dp[i][j] : i자리 오르막 수 중 j로 끝나는 수의 개수 
const int MOD = 10007;

int solution() 
{
	for (int i = 0; i <= 9; i++)
		dp[1][i] = 1;
	
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int k = 0; k <= j; k++)
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
		}
	}
	
	int answer = 0;
	for (int i = 0; i <= 9; i++)
		answer = (answer + dp[n][i]) % MOD;

	return answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	cout << solution();
}