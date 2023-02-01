#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
vector<vector<char>> map;
vector<bool> set_bool;
vector<vector<bool>> visited;

int moveX[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int moveY[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

// 8 방향이 모두 지뢰가 없는 칸인지 확인
bool check(int y, int x, int n)
{
	int count = 0;
	for (int i = 0; i < 8; i++)
	{
		int curX = x + moveX[i];
		int curY = y + moveY[i];
		if (curX >= 0 && curX <= n - 1 && curY >= 0 && curY <= n - 1)
		{
			if (map[curY][curX] == '*')
				return false;
		}
	}
	return true;
}

int bfs(int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j] && check(i, j, n) && map[i][j] == '.')
			{
				count++;
				queue<int> q;
				q.push(i * n + j);

				while (!q.empty())
				{
					int x = q.front() % n;
					int y = q.front() / n;
					visited[y][x] = true;
					q.pop();

					for (int i = 0; i < 8; i++)
					{
						int curX = x + moveX[i];
						int curY = y + moveY[i];

						if (curX >= 0 && curX <= n - 1 && curY >= 0 && curY <= n - 1 && !visited[curY][curX] && map[curY][curX] == '.')
						{
							visited[curY][curX] = true;
							if (check(curY, curX, n))
								q.push(curY * n + curX);
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == '.' && !visited[i][j])
				count++;
		}
	}
	return count;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;

		vector<char> set_vec(n, 0);
		vector<vector<char>> tmp_map(n, set_vec);
		set_bool.clear();
		set_bool.assign(n, false);
		visited.clear();
		visited.assign(n, set_bool);

		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				char ch;
				cin >> ch;
				tmp_map[j][k] = ch;
			}
		}
		map.clear();
		map = tmp_map;
		cout << '#' << i + 1 << ' ' << bfs(n) << endl;
	}
}