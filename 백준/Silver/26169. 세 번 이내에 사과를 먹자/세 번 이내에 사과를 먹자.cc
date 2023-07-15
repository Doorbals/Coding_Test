#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> tiii;

bool isMoreThan2 = false;
vector<bool> setBool(5, false);
vector<int> setInt(5, 0);
vector<vector<bool>> visited(5, setBool);
vector<vector<int>> arr(5, setInt);

int ySign[4] = { 1, -1, 0, 0 };
int xSign[4] = { 0, 0, -1, 1 };

void DFS(int y, int x, int depth, int count)
{
	// 방문 처리
	visited[y][x] = true;

	if (depth == 3)
	{
		if(count >= 2)
		{
			isMoreThan2 = true;
		}
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nextY = y + ySign[i];
		int nextX = x + xSign[i];

		if (nextY >= 5 || nextY < 0 || nextX >= 5 || nextX < 0)
			continue;
		
		if (arr[nextY][nextX] == -1)
			continue;

		if (visited[nextY][nextX])
			continue;

		if (arr[nextY][nextX] == 1)
			DFS(nextY, nextX, depth + 1, count + 1);
		else
			DFS(nextY, nextX, depth + 1, count);

		visited[nextY][nextX] = false;	// 다른 경로와 해당 노드를 공유하는 경우를 위해서 visited를 false로 되돌려줌.
	}
	
	if (depth == 0)
	{
		if (isMoreThan2)
			cout << 1;
		else
			cout << 0;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	// 맵 입력하기
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int n;
			cin >> n;
			arr[i][j] = n;
		}
	}

	// 현재 위치 입력하기
	int y, x;
	cin >> y;
	cin >> x;
	cin.ignore();

	DFS(y, x, 0, 0);
}