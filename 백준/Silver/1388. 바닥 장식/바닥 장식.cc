#include <bits/stdc++.h>

using namespace std;
typedef tuple<int, int, char> tiic;

void BFS(int y_size, int x_size, vector<tiic> arr)
{
	queue<tiic> q;	

	// 방문 여부 체크하는 visited 변수 초기화
	vector<int> set_bool(x_size, 0);
	vector<vector<int>> visited(y_size, set_bool);

	// 첫 칸 큐 삽입 및 방문 처리
	q.push(arr[0]);
	visited[0][0] = true;

	int count = 1;	// 총 판자 개수 저장하는 변수

	while(!q.empty())
	{
		int y = get<0>(q.front());
		int x = get<1>(q.front());
		char ch = get<2>(q.front());

		q.pop();

		// 오른쪽으로 이동
		if (x + 1 < x_size && !visited[y][x + 1])
		{
			visited[y][x + 1] = true;
			q.push(arr[y * x_size + x + 1]);

			char next_pattern = get<2>(arr[y * x_size + x + 1]);	// 다음 칸의 패턴

			if (next_pattern == '-')		// 이동한 칸이 '-' 모양인 경우
			{
				if (next_pattern != ch)
					count++;
			}
			else							// 이동한 칸이 '|' 모양인 경우
			{
				if (y > 0)	// 맨 위 행이 아닐 때
				{
					char next_pattern_up = get<2>(arr[(y - 1) * x_size + x + 1]);	// 다음 칸 위 칸의 패턴 
					if (next_pattern != next_pattern_up)
						count++;
				}
				else
					count++;
			}
		}

		// 아래쪽으로 이동
		if (y + 1 < y_size && !visited[y + 1][x])
		{
			visited[y + 1][x] = true;
			q.push(arr[(y + 1) * x_size + x]);

			char next_pattern = get<2>(arr[(y + 1) * x_size + x]);	// 다음 칸의 패턴

			if (next_pattern == '-')		// 이동한 칸이 '-' 모양인 경우
			{
				if (x > 0)	// 맨 왼쪽 열이 아닐 때
				{
					char next_pattern_left = get<2>(arr[(y + 1) * x_size + x - 1]);	// 다음 칸 왼쪽 칸의 패턴 
					if (next_pattern != next_pattern_left)
						count++;
				}
				else
					count++;
			}
			else							// 이동한 칸이 '|' 모양인 경우
			{
				if (next_pattern != ch)
					count++;
			}
		}
	}
	cout << count;
}

int main()
{	
	int y, x; 
	cin >> y;
	cin >> x;
	cin.ignore();

	vector<tuple<int, int, char>> arr(y * x);	// 각 칸에 대해 (y좌표, x좌표, 판자 모양) 저장

	// 바닥 모양 입력하기
	for (int i = 0; i < y; i++)
	{
		string input;
		getline(cin, input);
		
		for (int j = 0; j < x; j++)
		{
			arr[i * x + j] = tiic(i, j, input[j]);
		}
	}
    
	BFS(y, x, arr);
}