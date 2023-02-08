#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int days[200001];
int maxPeriod;
vector<int> blanks;

int binary_search(int n, int p)
{
	vector<int> answers;
	for (int k = 0; k < n; k++)
	{
		int start = k, end = n - 1;
		int answer = 0;
		while (end >= start)
		{
			int mid = start + (end - start) / 2;
			int didntStudy = 0, curP = p;
			didntStudy = blanks[mid] - blanks[k];

			curP = (p - didntStudy > 0) ? p - didntStudy : 0;

			if (didntStudy > p)
				end = mid - 1;
			else
			{
				answer = days[mid] - days[k] + 1 + curP;
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
		blanks.push_back(0);
		for (int j = 0; j < n - 1; j++)
		{
			blankCount += days[j + 1] - days[j] - 1;
			blanks.push_back(blankCount);
		}

		cout << '#' << i + 1 << ' ' << binary_search(n, p) << endl;
		maxPeriod = 0;
	}
}