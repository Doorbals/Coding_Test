#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> stones;

int solution(vector<int> stones, int k) 
{
	int start = 1, end = 200000000, answer;
	vector<int> stones_copy;
	while (end >= start)
	{
		int mid = start + (end - start) / 2;
		stones_copy = stones;

		int count = 0;
		for (int i = 0; i < stones_copy.size(); i++)
		{
			if (stones_copy[i] - mid <= 0)
				count++;
			else
				count = 0;

			if (count >= k)
				break;
		}
		if (count >= k)
			end = mid - 1;
		else
		{
			answer = mid;
			start = mid + 1;
		}
	}
	return answer + 1;
}