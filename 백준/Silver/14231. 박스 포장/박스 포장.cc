#include <iostream>

using namespace std;
int dp[5001];
int boxes[5001];

void solution(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (boxes[j] < boxes[i])
			{
				if(dp[i] < dp[j] + 1)	
					dp[i] = dp[j] + 1;
			}
		}
	}
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
		cin >> boxes[i];
		dp[i] = 1;
	}

	solution(n);
		
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (dp[i] > max)
			max = dp[i];
	}
	cout << max;

	return 0;
}