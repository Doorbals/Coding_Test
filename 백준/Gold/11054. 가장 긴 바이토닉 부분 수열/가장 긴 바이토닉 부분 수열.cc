#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>
using namespace std;
int nums[1001];
int nums2[1001];
int dp1[1001];		
int dp2[1001];

int solution(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (nums[i] > nums[j] && dp1[j] + 1 > dp1[i])
				dp1[i] = dp1[j] + 1;

			if (nums2[i] > nums2[j] && dp2[j] + 1 > dp2[i])
				dp2[i] = dp2[j] + 1;
		}
	}

	int maxValue = 0;
	for (int i = 0; i <= n; i++)
	{
		int sum = dp1[i] + dp2[n - i + 1] - 1;
		if (maxValue < sum)
			maxValue = sum;
	}
	return maxValue;
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
		nums2[n - i + 1] = nums[i];
		dp1[i] = 1;
		dp2[i] = 1;
	}

	cout << solution(n);
}