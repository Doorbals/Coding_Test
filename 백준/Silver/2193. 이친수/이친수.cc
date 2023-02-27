#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>
using namespace std;

int n;
long long dp[91][2];		// dp[i][j] : i 길이의 이진수 중 마지막 수가 j인 경우의 개수 (j는 0 또는 1)

long long solution() 
{
	// 1 길이 이진수는 1밖에 없음. 2 길이 이진수는 10밖에 없음.
	dp[1][1] = 1;
	dp[2][0] = 1;

	for (int i = 3; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];		// 현재 길이의 0으로 끝나는 수는 이전 길이 수 중 0으로 끝나는 수와 1로 끝나는 수 두 가지 모두에서 파생 가능
		dp[i][1] = dp[i - 1][0];					// 현재 길이의 1로 끝나는 수는 이전 길이 수 중 0으로 끝나는 수에서만 파생 가능 (1이 연속으로 올 수 없으므로)
	}

	return dp[n][0] + dp[n][1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	cout << solution();
}