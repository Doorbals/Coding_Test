#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <string>

using namespace std;
long long dp[31][31];

long long solution(int a, int b)
{
	for (int i = 1; i <= b; i++)
		dp[1][i] = i;

	for (int i = 2; i <= a; i++)
	{
		for (int j = i; j <= b; j++)
		{
			for (int k = i - 1; k <= j - 1; k++)
				dp[i][j] += dp[i - 1][k];
		}
	}

	return dp[a][b];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << solution(a, b) << endl;
		
		for (int j = 0; j < 31; j++)
		{
			for (int k = 0; k < 31; k++)
				dp[j][k] = 0;		
		}
	}
}