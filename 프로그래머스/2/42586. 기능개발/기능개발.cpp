#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
	vector<int> answer;
	queue<int> period;

	for (int i = 0; i < progresses.size(); i++)
	{
		int left = 100 - progresses[i];
		period.push(ceil(left / static_cast<float>(speeds[i])));
	}

	int count = 0;
	while (!period.empty())
	{
		int cur = period.front();
		period.pop();
		count = 1;

		while (cur >= period.front() && !period.empty())
		{
			count++;
			period.pop();
		}

		answer.push_back(count);
	}

	return answer;
}