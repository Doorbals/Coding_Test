#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>

using namespace std;

long long dp[8][100001];			// dp[i][j] : i번 건물에 j분에 도착하는 경우의 수
const long long MOD = 1000000007;
int n;

// 정보과학관 : 0 / 전산관 : 1 / 미래관 : 2 / 신양관 : 3 / 한경직기념관 : 4 / 진리관 : 5 / 학생회관 : 6 / 형남공학관 : 7
long long solution()
{
	dp[0][0] = 1;

	// i번 건물에 j분에 도착하는 경우의 수는 (i번 건물에 연결된 건물들에 i-1분에 도착하는 경우의 수의 합)
	for (int i = 1; i <= n + 1; i++)
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