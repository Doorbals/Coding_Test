#include <iostream>
using namespace std;

int soldiers[2000];
int dp[2000];

int lis(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (soldiers[i] > soldiers[j])
			{
				if (dp[j] + 1 > dp[i])
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
	return (n - max);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = n - 1; i >= 0; i--)
	{
		int p;
		cin >> soldiers[i];
		dp[i] = 1;
	}
	cout << lis(n);
}