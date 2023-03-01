#include <iostream>
#include <algorithm>
using namespace std;

int nums[1001];
int dp[41];

void recursive(int n)
{
	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= n; i++)\
		dp[i] = dp[i - 1] + dp[i - 2];

	cout << dp[n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	recursive(n);
	cout << ' ' << n - 2;
}