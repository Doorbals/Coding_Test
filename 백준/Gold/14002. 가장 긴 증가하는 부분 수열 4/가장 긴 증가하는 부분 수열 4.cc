#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>
#include <string>
using namespace std;

int nums[1001];
int dp[1001];
string dp2[1001];

void solution(int n)
{
	int maxIndex = 1, maxCount = 1;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (nums[j] < nums[i] && dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j] + 1;
				dp2[i] = dp2[j];
				if (maxCount < dp[i])
				{
					maxCount = dp[i];
					maxIndex = i;
				}
			}
		}
		dp2[i] += (to_string(nums[i]) + " ");
	}
	cout << maxCount << endl;
	cout << dp2[maxIndex];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> nums[i];
		dp[i] = 1;
	}

	solution(n);
}