#include <bits/stdc++.h>

using namespace std;


void BFS(int n, vector<tuple<int, int, int>> arr)
{
	queue<tuple<int, int, int>> q;

	q.push(arr[0]);

	while (!q.empty())
	{
		int y = get<0>(q.front());
		int x = get<1>(q.front());
		int value = get<2>(q.front());

		if (value == 0)
		{
			cout << "Hing";
			return;
		}
			
		q.pop();
			
		if (x + value < n)
		{
			q.push(arr[y * n + x + value]);

			if (get<2>(arr[y * n + x + value]) == -1)
			{
				cout << "HaruHaru";
				return;
			}
		}

		if (y + value < n)
		{
			q.push(arr[(y + value) * n + x]);

			if (get<2>(arr[(y + value) * n + x]) == -1)
			{
				cout << "HaruHaru";
				return;
			}
		}
	}
	cout << "Hing";
}

int main()
{	
	int n; 
	cin >> n;
	cin.ignore();

	vector<tuple<int, int, int>> arr(n * n);

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


