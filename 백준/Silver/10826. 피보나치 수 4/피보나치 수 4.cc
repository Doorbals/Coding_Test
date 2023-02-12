#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <string>

using namespace std;
string dp[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i <= n; i++)
	{
		if (i == 0)
			dp[i] = "0";
		else if (i == 1)
			dp[i] = "1";
		else
		{
			vector<char> num(dp[i - 1].size());
			int carry = 0;
			for (int j = dp[i - 1].size() - 1; j >= 0; j--)
			{
				int sum = 0;
				if (dp[i - 1].size() > dp[i - 2].size()) 
				{
					if(j - 1 >= 0)
						sum = (dp[i - 1][j]) - '0' + (dp[i - 2][j - 1]) - '0' + carry;
					else
						sum = (dp[i - 1][j]) - '0' + carry;
				}
				else
					sum = (dp[i - 1][j]) - '0' + (dp[i - 2][j]) - '0' + carry;
				int quot = sum % 10;
				carry = sum / 10;
				num[j] = quot + '0';
			}
			
			string str;
			if (carry > 0)
				str += to_string(carry);

			for (int j = 0; j < num.size(); j++)
				str += num[j];
			
			dp[i] = str;
		}
	}
	cout << dp[n];
}