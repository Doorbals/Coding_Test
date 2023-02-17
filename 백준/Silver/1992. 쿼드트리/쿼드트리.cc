#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>

using namespace std;
int map[65][65];

void compress(int n, int y, int x)
{
	if (n == 1)
	{
		cout << map[y][x];
		return;
	}
		 
	bool exist0 = false;
	bool exist1 = false;

	for (int i = y; i < y + n; i++)
	{
		for (int j = x; j < x + n; j++)
		{
			if (map[i][j] == 0)
				exist0 = true;
			else
				exist1 = true;

			if (exist0 && exist1)
				break;
		}
		if (exist0 && exist1)
			break;
	}

	if (exist0 && exist1)
	{
		cout << '(';
		compress(n / 2, y, x);					// 2사분면
		compress(n / 2, y, x + n / 2);			// 1사분면
		compress(n / 2, y + n / 2, x);			// 3사분면
		compress(n / 2, y + n / 2, x + n / 2);	// 4사분면
		cout << ')';
	}
	else if (exist0)
		cout << 0;
	else
		cout << 1;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < n; j++)
		{
			map[i][j] = str[j] - '0';
		}
	}

	compress(n, 0, 0);
}