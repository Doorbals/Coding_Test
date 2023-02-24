#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>
using namespace std;

int n;
int dp[100001];
int maxValue[100001];
vector<int> nums;

void solution()
{
	dp[1] = nums[1];
	maxValue[1] = nums[1];
		
	for (int i = 2; i <= n; i++)
	{
		if (dp[i - 1] > 0)
			dp[i] = dp[i - 1] + nums[i];
		else
			dp[i] = nums[i];

		maxValue[i] = max(maxValue[i - 1], dp[i]);
	}
	cout << maxValue[n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	nums.push_back(0);
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		nums.push_back(num);
	}
	solution();
}