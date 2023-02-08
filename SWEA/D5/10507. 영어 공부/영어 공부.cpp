#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>

using namespace std;
int days[200001];
int maxPeriod;
vector<int> blanks;		// days의 첫 날짜부터 다른 날짜까지 공백(문제 안 푼 날)을 저장 (ex. [1]에는 days[0] ~ days[1] 사이의 안 푼 일수) 

int binary_search(int n, int p)
{
	vector<int> answers;	// 각 날짜에서 시작했을 때 가장 긴 연속 기간을 저장

	// days[i] 날짜부터 시작했을 때 가장 긴 연속 기간을 이진 탐색으로 구한다.
	for (int i = 0; i < n; i++)
	{
		int start = i, end = n - 1;
		int answer = 0;
		while (end >= start)
		{
			int mid = start + (end - start) / 2;
			int didntStudy = 0, curP = p;			// didntStudy : days[i] 날짜에서 days[mid] 날짜까지 중 공백(공부 안 한 일수) / curP : days[i]에서 days[mid]까지 연속시켰을 때 남는 p
			didntStudy = blanks[mid] - blanks[i];

			curP = (p - didntStudy > 0) ? p - didntStudy : 0;		// 남은 p가 음수면 0으로 처리

			if (didntStudy > p)			// 추가로 체크할 수 있는 날보다 공백 개수가 더 많음 -> days[mid] 이상의 날짜는 불가능하므로 그 아래 값을 탐색
				end = mid - 1;
			else                        // 추가로 체크할 수 있는 날을 딱 맞춰 사용했거나, 더 적게 사용 -> days[i] ~ days[mid]일 때의 연속 기간을 answer로 설정해두고, 그 위 값도 탐색
			{
				answer = days[mid] - days[i] + 1 + curP;
				start = mid + 1;
			}
		}
		answers.push_back(answer);
		if (maxPeriod < answer)
			maxPeriod = answer;
	}
	return maxPeriod;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n, p;
		cin >> n >> p;

		for (int j = 0; j < n; j++)
		{
			int day;
			cin >> day;
			days[j] = day;
		}

		int blankCount = 0;
		blanks.clear();
		blanks.push_back(0);				// 맨 첫 날짜까지는 공백 X

		// blankCount에 현재 순서 날짜와 다음 순서 날짜 사이의 공백 누적하고 이를 blanks에 삽입 
		for (int j = 0; j < n - 1; j++)		
		{
			blankCount += days[j + 1] - days[j] - 1;
			blanks.push_back(blankCount);
		}

		cout << '#' << i + 1 << ' ' << binary_search(n, p) << endl;
		maxPeriod = 0;
	}
}