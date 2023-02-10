#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int moveX[3] = {1, 0, 1};		// 오른쪽, 아래, 대각선 오른쪽 아래
int moveY[3] = {0, 1, 1};

int solution(int m, int n, vector<string> board)
{
	int answer = 0;
	vector<vector<char>> boardArr(m);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			boardArr[i].push_back(board[i][j]);
	}

	while (true)
	{
		vector<pii> removeBlocks;
		for (int i = 0; i < m - 1; i++)
		{
			for (int j = 0; j < n - 1; j++)
			{
				char curChar = boardArr[i][j];
				for (int k = 0; k < 3; k++)
				{
					if (boardArr[i + moveY[k]][j + moveX[k]] != curChar || curChar == '.')
						break;
					if (k == 2)
						removeBlocks.push_back(pii(i, j));
				}
			}
		}
		if (removeBlocks.size() == 0)
			break;

		vector<bool> set_bool(n);
		vector<vector<bool>> checkRemove(n, set_bool);

		for (int i = 0; i < removeBlocks.size(); i++)
		{
			int y = removeBlocks[i].first;
			int x = removeBlocks[i].second;
			checkRemove[y][x] = true;
			for (int j = 0; j < 3; j++)
				checkRemove[y + moveY[j]][x + moveX[j]] = true;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (checkRemove[i][j])
				{
					for (int k = i; k >= 0; k--)
					{
						if (k == 0)
							boardArr[k][j] = '.';
						else
							boardArr[k][j] = boardArr[k - 1][j];
						
					}
					answer++;
				}
			}
		}
	}
	return answer;
}