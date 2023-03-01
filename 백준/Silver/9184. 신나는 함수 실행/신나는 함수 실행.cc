#include <iostream>
#include <algorithm>
using namespace std;

int dp[101][101][101];

int solution(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	else if (a > 20 || b > 20 || c > 20)
	{
		if (dp[20 + 50][20 + 50][20 + 50] != 0)
			return dp[20 + 50][20 + 50][20 + 50];
		else
		{
			int curNum = solution(20, 20, 20);
			dp[20 + 50][20 + 50][20 + 50] = curNum;
			return curNum;
		}
			
	}
	else if (a < b && b < c)
	{
		int answer = 0;
		int curNum = 0;
		if (dp[a + 50][b + 50][c - 1 + 50] != 0)
			answer += dp[a + 50][b + 50][c - 1 + 50];
		else
		{
			curNum = solution(a, b, c - 1);
			dp[a + 50][b + 50][c - 1 + 50] = curNum;
			answer += curNum;
		}
			
		if (dp[a + 50][b - 1 + 50][c - 1 + 50] != 0)
			answer += dp[a + 50][b - 1 + 50][c - 1 + 50];
		else
		{
			curNum = solution(a, b - 1, c - 1);
			dp[a + 50][b - 1 + 50][c - 1 + 50] = curNum;
			answer += curNum;
		}
			
		if (dp[a + 50][b - 1 + 50][c + 50] != 0)
			answer -= dp[a + 50][b - 1 + 50][c + 50];
		else
		{
			curNum = solution(a, b - 1, c);
			dp[a + 50][b - 1 + 50][c + 50] = curNum;
			answer -= curNum;
		}

		return answer;
	}
	else
	{
		int answer = 0;
		int curNum = 0;
		if (dp[a - 1 + 50][b + 50][c + 50] != 0)
			answer += dp[a - 1 + 50][b + 50][c + 50];
		else
		{
			curNum = solution(a - 1, b, c);
			dp[a - 1 + 50][b + 50][c + 50] = curNum;
			answer += curNum;
		}

		if (dp[a - 1 + 50][b - 1 + 50][c + 50] != 0)
			answer += dp[a - 1 + 50][b - 1 + 50][c + 50];
		else
		{
			curNum = solution(a - 1, b - 1, c);
			dp[a - 1 + 50][b - 1 + 50][c + 50] = curNum;
			answer += curNum;
		}

		if (dp[a - 1 + 50][b + 50][c - 1 + 50] != 0)
			answer += dp[a - 1 + 50][b + 50][c - 1 + 50];
		else
		{
			curNum = solution(a - 1, b, c - 1);
			dp[a - 1 + 50][b + 50][c - 1 + 50] = curNum;
			answer += curNum;
		}

		if (dp[a - 1 + 50][b - 1 + 50][c - 1 + 50] != 0)
			answer -= dp[a - 1 + 50][b - 1 + 50][c - 1 + 50];
		else
		{
			curNum = solution(a - 1, b - 1, c - 1);
			dp[a - 1 + 50][b - 1 + 50][c - 1 + 50] = curNum;
			answer -= curNum;
		} 

		return answer;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	while (true)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << solution(a, b, c) << endl;
	}
}