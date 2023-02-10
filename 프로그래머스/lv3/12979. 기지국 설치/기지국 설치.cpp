#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
	int answer = 0, curIndex = 1;

	for (int i = 0; i < stations.size(); i++)
	{
		int curRange = stations[i] - w - curIndex;
		answer += ceil(curRange / (2.0 * w + 1));
		curIndex = stations[i] + w + 1;
	}

	if(curIndex <= n)
		answer += ceil((n + 1 - curIndex) / (2.0 * w + 1));

	return answer;
}