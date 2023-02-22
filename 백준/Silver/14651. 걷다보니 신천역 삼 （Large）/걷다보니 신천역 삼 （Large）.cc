#include <iostream>
#include <algorithm>

using namespace std;
int n;
long long dp[40000];
const int MOD = 1000000009;

int solution()
{
	dp[2] = 2;
	for (int i = 3; i <= n; i++)
		dp[i] = dp[i - 1] * 3 % MOD;

	return dp[n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	cout << solution() << endl;
}