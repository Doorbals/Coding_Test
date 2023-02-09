#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>

using namespace std;
typedef pair<int, int> pii;
pii consultings[16];
int dp[16];

int solution(int start, int n)
{
	if (dp[start] == -1)
	{
		int max = 0;
		for (int i = start + consultings[start].first; i <= n + 1; i++)
		{
			int curProfit = consultings[start].second + solution(i, n);
			if (max < curProfit)
				max = curProfit;
		}
		dp[start] = max;
		return max;
	}
	else
		return dp[start];
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		int t, p;
		scanf("%d %d", &t, &p);
		consultings[i] = pii(t, p);
	}

	for (int i = 1; i <= n; i++)
		dp[i] = -1;
	
	int max = 0;
	for (int i = 1; i <= n; i++)
	{
		int curProfit = solution(i, n);
		if (max < curProfit)
			max = curProfit;
	}
	cout << max;
	return 0;
}