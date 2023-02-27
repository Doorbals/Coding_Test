#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>
using namespace std;

int n;
int dp[10001];
vector<int> glasses;

int solution() 
{
	dp[1] = glasses[1];
	dp[2] = glasses[1] + glasses[2];

	for (int i = 3; i <= n; i++)
		dp[i] = max({ dp[i - 1], dp[i - 3] + glasses[i - 1] + glasses[i], dp[i - 2] + glasses[i] });

	return dp[n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	glasses.push_back(0);
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		glasses.push_back(num);
	}
	cout << solution();
}