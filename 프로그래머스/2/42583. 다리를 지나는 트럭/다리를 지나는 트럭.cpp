#include <string>
#include <vector>
#include <queue>

using namespace std;

struct info
{
	int num = 0;
	int popTime = 0;
};

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
	queue<info> q;

	int totalWeight = truck_weights[0];
	int order = 1;
	int curTime = 0;
	q.push(info{ 0, curTime + bridge_length });

	while (true)
	{
		curTime++;

		info i;
		if (!q.empty())
		{
			i = q.front();
			if (i.popTime == curTime)
			{
				q.pop();
				totalWeight -= truck_weights[i.num];
			}
		}
		else
		{
			return curTime;
		}

		if (order < truck_weights.size() && totalWeight + truck_weights[order] <= weight)
		{
			totalWeight += truck_weights[order];
			q.push(info{ order, curTime + bridge_length });
			order++;
		}
	}
}