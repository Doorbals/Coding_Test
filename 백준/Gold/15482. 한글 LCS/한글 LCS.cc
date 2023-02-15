#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
int dp[2000][2000];
vector<char> string1;
vector<char> string2;
int longest = 0;

int LCS()
{
	for (int i = 1; i <= string1.size() / 3; i++)
	{
		for (int j = 1; j <= string2.size() / 3; j++)
		{
			if (string1[i * 3 - 3] == string2[j * 3 - 3] && string1[i * 3 - 2] == string2[j * 3 - 2] && string1[i * 3 - 1] == string2[j * 3 - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

			longest = max(longest, dp[i][j]);
		}
	}
	return longest;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string str1;
	string str2;
	cin >> str1;
	cin >> str2;

	for (int i = 0; i < str1.size(); i++)
		string1.push_back(str1[i]);
	
	for (int i = 0; i < str2.size(); i++)
		string2.push_back(str2[i]);

	cout << LCS();
}