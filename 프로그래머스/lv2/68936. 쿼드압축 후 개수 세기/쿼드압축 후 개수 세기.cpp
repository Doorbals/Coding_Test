#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>
using namespace std;
vector<vector<int>> map;
vector<int> result(2);

void compress(int n, int y, int x)
{
	if (n == 1)
	{
		if (map[y][x] == 0)
			result[0]++;
		else
			result[1]++;
		return;
	}

	bool exist_0 = false;
	bool exist_1 = false;

	for (int i = y; i < y + n; i++)
	{
		for (int j = x; j < x + n; j++)
		{
			if (map[i][j] == 0)
				exist_0 = true;
			else
				exist_1 = true;

			if (exist_0 && exist_1)
				break;
		}
		if (exist_0 && exist_1)
			break;
	}

	if (exist_0 && exist_1)
	{
		compress(n / 2, y, x);
		compress(n / 2, y, x + n / 2);
		compress(n / 2, y + n / 2, x);
		compress(n / 2, y + n / 2, x + n / 2);
	}
	else if (exist_0)
		result[0]++;
	else
		result[1]++;
}

vector<int> solution(vector<vector<int>> arr) 
{
	map = arr;
	compress(map.size(), 0, 0);
	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	vector<vector<int>> arr = { {1, 1, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 1}, {1, 1, 1, 1} };
	vector<int> result = solution(arr);
	
	cout << result[0] << ' ' << result[1];
}
