#include <bits/stdc++.h>

using namespace std;

queue<tuple<int, int, int>> q;	// tuple : 세 개의 변수 저장할 수 있는 구조 (방문한 칸의 y좌표, x좌표, 누적 칸수)

int BFS(vector<vector<int>> maps, int start_y, int start_x)
{
	int answer = 1;
	int count = 1;

	int n, m;
	n = maps[0].size();		// 맵 가로 길이
	m = maps.size();		// 맵 세로 길이

	vector<bool> set_bool(n, false);	// visited 초기화 하기 위한 bool 배열
	vector<vector<bool>> visited(m, set_bool); // 각 노드 방문 여부 저장하는 bool 변수 배열의 배열

	// 첫 위치 방문 처리 하고 큐에 삽입
	visited[start_y][start_x] = true;
	q.push(tuple<int, int, int>(start_y, start_x, 1));

	while (!q.empty())
	{
		int x, y, count;
		y = get<0>(q.front());	// 가장 앞에 있는 노드의 tuple 중 첫번째 값 반환 (y좌표)
		x = get<1>(q.front());	// 가장 앞에 있는 노드의 tuple 중 두번째 값 반환 (x좌표)
		count = get<2>(q.front()); // 가장 앞에 있는 노드의 tuple 중 세번째 값 반환 (누적 칸수)
		q.pop();
        
		// 현재 위치의 왼쪽 노드 큐에 추가
		if (x > 0 && maps[y][x - 1] != 0 && visited[y][x - 1] == false)
		{
			q.push(tuple<int, int, int>(y, x - 1, count + 1));	// 다음 노드의 누적 칸수 = 이전 노드의 누적 칸수 + 1
			visited[y][x - 1] = true;
		}

		// 현재 위치의 오른쪽 노드 큐에 추가
		if (x < n - 1 && maps[y][x + 1] != 0 && visited[y][x + 1] == false)
		{
			q.push(tuple<int, int, int>(y, x + 1, count + 1));
			visited[y][x + 1] = true;
		}

		// 현재 위치의 위쪽 노드 큐에 추가
		if (y > 0 && maps[y - 1][x] != 0 && visited[y - 1][x] == false)
		{
			q.push(tuple<int, int, int>(y - 1, x, count + 1));
			visited[y - 1][x] = true;
		}

		// 현재 위치의 아래쪽 노드 큐에 추가
		if (y < m - 1 && maps[y + 1][x] != 0 && visited[y + 1][x] == false)
		{
			q.push(tuple<int, int, int>(y + 1, x, count + 1));
			visited[y + 1][x] = true;
		}

		if (y == m - 1 && x == n - 1)
			return count;
		else if (q.empty())
			return -1;
	}
}

int solution(vector<vector<int> > maps)
{
	int answer = BFS(maps, 0, 0);
	return answer;
}