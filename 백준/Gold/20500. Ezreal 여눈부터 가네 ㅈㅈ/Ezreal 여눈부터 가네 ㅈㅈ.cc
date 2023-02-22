#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int dp[1516];	// dp[n]에는 1, 5로 만들 수 있는 n 자리 수 중 15의 배수의 개수가 저장됨.
const int MOD = 1000000007;

int solution()
{
	dp[1] = 0;
	dp[2] = 1;

	int count = 0;
	for (int i = 3; i <= n; i++)			// i가 홀수 일 때 dp[i] : (이전 자리수의 dp * 2 - 1), i가 짝수 일 때 dp[i] : (이전 자리수의 dp * 2 + 1)
	{
		if (i % 2 == 0)
			dp[i] = (dp[i - 1] * 2 + 1) % MOD;
		else
			dp[i] = (dp[i - 1] * 2 - 1) % MOD;
	}
		
	return dp[n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	cout << solution() << endl;
}