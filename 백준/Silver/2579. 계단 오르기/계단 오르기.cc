#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>

using namespace std;
int n;
int dp[301];
vector<int> scores;

int solution()
{
	dp[1] = scores[1];
	dp[2] = scores[1] + scores[2];

	for (int i = 3; i <= n; i++)
		dp[i] = max(dp[i - 2] + scores[i], dp[i - 3] + scores[i - 1] + scores[i]);
	
	return dp[n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;

	scores.push_back(0);
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		scores.push_back(num);
	}
		
	cout << solution();
}