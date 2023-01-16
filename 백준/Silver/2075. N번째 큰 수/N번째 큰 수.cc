#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int n = 0;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;	// 오름차순 정렬 우선순위 큐

	int min = -1000000000;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int num;
			cin >> num;

			// 첫 행에서 가장 큰 수를 min으로 설정하고, 그 수를 큐에 삽입
			if (i == 0)
			{
				if (num > min)
					min = num;	
				
				if (j == n - 1)
					pq.push(min);
			}
			else
			{
				if (num > pq.top())
					pq.push(num);

				if (pq.size() > n)
					pq.pop();
			}
		}
	}

	cout << pq.top();
}