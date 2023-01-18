#include <bits/stdc++.h>

using namespace std;
int visited[65][65];

void BFS(int n, vector<tuple<int, int, int>> arr)
{
	queue<tuple<int, int, int>> q;
	q.push(arr[0]);		// 가장 첫 칸에 대한 데이터 큐에 삽입

	while (!q.empty())
	{
		// 최전방 노드에 저장된 데이터들을 변수로 저장 후 큐에서 삭제
		int y = get<0>(q.front());	// y좌표
		int x = get<1>(q.front());	// x좌표
		int value = get<2>(q.front());	// 칸의 값
		q.pop();

		// 칸의 값이 0이면 더 이상 이동 불가능 (문제 잘 읽을 것!)
		if (value == 0)
		{
			cout << "Hing";
			return;
		}

		// 오른쪽으로 이동하는 경우 : (현재 x 좌표 + 칸의 값 < n) 일 때 이동 가능.)
		if (x + value < n && !visited[y][x + value])
		{
			q.push(arr[y * n + x + value]);		// arr 벡터에 접근할 때는 y 좌표에 n을 곱해주어야 함. -> (1, 0) 좌표의 칸은 arr[3]에 저장
			visited[y][x + value] = true;
			if (get<2>(arr[y * n + x + value]) == -1)	// 목표 칸에 도착하면 HaruHaru 출력
			{
				cout << "HaruHaru";
				return;
			}
		}

		// 아래로 이동하는 경우 : (현재 y 좌표 + 칸의 값 < n) 일 때 이동 가능
		if (y + value < n && !visited[y + value][x])
		{
			q.push(arr[(y + value) * n + x]);
			visited[y + value][x];
			if (get<2>(arr[(y + value) * n + x]) == -1)
			{
				cout << "HaruHaru";
				return;
			}
		}
	}
	cout << "Hing";		// 큐가 비워질 때까지 도착 못하면 도착 지점 도달 불가능
}

int main()
{
	int n;
	cin >> n;
	cin.ignore();

	vector<tuple<int, int, int>> arr(n * n);	// 각 칸에 대해 (y좌표, x좌표, 칸의 값) 저장 (arr[0] = (0, 0), arr[1] = (0, 1), ... , arr[3] = (1, 0), arr[4] = (1, 1), ... 과 같은 순서)

	// 맵 입력하기
	for (int i = 0; i < n; i++)
	{
		string input;
		getline(cin, input);

		istringstream ss(input);
		string stringBuffer;

		int j = 0;
		while (getline(ss, stringBuffer, ' '))
		{
			arr[i * n + j] = tuple<int, int, int>(i, j, stoi(stringBuffer));
			j++;
		}
	}

	BFS(n, arr);
}


