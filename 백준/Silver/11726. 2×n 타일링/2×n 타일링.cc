#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[1001];

void solution()
{
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;

	cout << dp[n] ;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	solution();
}