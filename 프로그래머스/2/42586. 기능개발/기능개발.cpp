#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> period;

	for (int i = 0; i < progresses.size(); i++)
	{
		int left = 100 - progresses[i];
		period.push_back(ceil(left / static_cast<float>(speeds[i])));
	}

	int count = 0;
    int maxPeriod = 0;
	for (int i = 0; i < period.size(); i++)
	{
		count++;
        
        if(i == period.size() - 1)
        {
            answer.push_back(count);
            break;
        }
        
        if(maxPeriod < period[i])
        {
            maxPeriod = period[i];
        }
        
		if (period[i] < period[i + 1] && maxPeriod < period[i + 1])
		{
			answer.push_back(count);
			count = 0;
            maxPeriod = 0;
		}
	}
    
	return answer;
}