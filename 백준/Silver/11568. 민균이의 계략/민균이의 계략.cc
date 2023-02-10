#include <iostream>

using namespace std;
int cards[1001];
int dp[1001];

int solution(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (cards[j] < cards[i])
			{
				if (dp[i] < dp[j] + 1)
					dp[i] = dp[j] + 1;
			}
		}
	}

	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (max < dp[i])
			max = dp[i];
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
		int num;
		cin >> cards[i];
		dp[i] = 1;
	}

	cout << solution(n);
}