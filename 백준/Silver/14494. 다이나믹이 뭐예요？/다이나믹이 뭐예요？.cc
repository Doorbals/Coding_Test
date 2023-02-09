#include <iostream>
using namespace std;

const int DIVIDE_NUM = 1000000007;
long long dp[1001][1001];

long long solution(int n, int m)
{
	if (n == 1 || m == 1)
		return 1;

	if (dp[n][m] != 0)
		return dp[n][m];
	else
	{
		dp[n][m] = (solution(n - 1, m) + solution(n, m - 1) + solution(n - 1, m - 1)) % DIVIDE_NUM;
		return dp[n][m];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	cout << solution(n, m);
}