#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>

using namespace std;
vector<char> string1;
vector<char> string2;
int dp[1001][1001];

int solution()
{
	for (int i = 1; i <= string1.size(); i++)
	{
		for (int j = 1; j <= string2.size(); j++)
		{
			if (string1[i - 1] == string2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	int max = 0;
	for (int i = 1; i <= string1.size(); i++)
	{
		for (int j = 1; j <= string2.size(); j++)
		{
			if (max < dp[i][j])
				max = dp[i][j];
		}
	}
	return max;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string str1, str2;
	cin >> str1 >> str2;

	for (int i = 0; i < str1.size(); i++)
		string1.push_back(str1[i]);
	
	for (int i = 0; i < str2.size(); i++)
		string2.push_back(str2[i]);

	cout << solution();
}