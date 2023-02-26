#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> units;
long long dp[10001];

int solution() 
{
	dp[0] = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = units[i]; j <= k; j++)
		{
			dp[j] += dp[j - units[i]];
		}
	}
	return dp[k];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		units.push_back(num);
	}
	cout << solution();
}