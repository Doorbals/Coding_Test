#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>

using namespace std;
vector<string> arr1;
vector<string> arr2;
int dp[1001][1001];

int solution()
{
	for (int i = 1; i <= arr1[0].size(); i++)
	{
		for (int j = 1; j <= arr2[0].size(); j++)
		{
			if (arr1[0][i - 1] == arr2[0][j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
			{
				if (dp[i - 1][j] < dp[i][j - 1])
					dp[i][j] = dp[i][j - 1];
				else
					dp[i][j] = dp[i - 1][j];
			}
		}
	}

	int max = 0;
	for (int i = 1; i <= arr1[0].size(); i++)
	{
		for (int j = 1; j <= arr2[0].size(); j++)
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

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str1, str2;
		cin >> str1;
		cin >> str2;
		arr2.push_back(str1);
		arr1.push_back(str2);

		for (int j = 0; j <= str2.size(); j++)
		{
			for (int j = 0; j <= str1.size(); j++)
				dp[i][j] = 0;
		}
		cout << '#' << i + 1 << ' ' << solution() << endl;

		arr1.clear();
		arr2.clear();
	}
}