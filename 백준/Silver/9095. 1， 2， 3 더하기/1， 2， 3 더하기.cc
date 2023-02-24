#include <iostream>
#include <algorithm>
using namespace std;

int n;
int target;
int dp[11];			
int count_1[11];

int solution()
{
	dp[1] = 1;
	count_1[1] = 1;
	dp[2] = 2;
	count_1[2] = 1;
	
	for (int i = 3; i <= target; i++)
	{
		dp[i] = dp[i - 1] * 2 - count_1[i - 3];
		count_1[i] = dp[i - 1];
	}
	return dp[target];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> target;
		cout << solution() << endl;
	}
}