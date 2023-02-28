#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long dp[1000001];		// dp[i] : i 길이의 이진수의 개수
const int MOD = 15746;

long long solution() 
{
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++)
		dp[i] = (dp[i - 2] + dp[i - 1]) % MOD;

	return dp[n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	cout << solution();
}