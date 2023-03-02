#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, m;
int dp[1001][1001];
string str1, str2, answer;

void solution()
{
	int maxCount = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				if (maxCount < dp[i][j])
				{
					maxCount = dp[i][j];
				}
			}
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[n][m] << endl;
	
	int i = n, j = m;
	while (i != 0 && j != 0)
	{
		if (str1[i - 1] == str2[j - 1])
		{
			answer += str1[i - 1];
			i--;
			j--;
		}
		else
		{
			if (dp[i][j] == dp[i - 1][j])
				i--;
			else if (dp[i][j] == dp[i][j - 1])
				j--;
		}
	}

	for(int i = answer.length() - 1; i >= 0; i--)
		cout << answer[i];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> str1;
	cin >> str2;
	n = str1.size();
	m = str2.size();
	solution();
}