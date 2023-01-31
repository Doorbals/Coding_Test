#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>

using namespace std;
vector<int> down;				// 석순들 길이 저장
vector<int> up;					// 종유석들 길이 저장
vector<int> countEachFloor;		// 각 구간 장애물 개수 저장

long long lowerBoundDown(int currentFloor, int length)
{
	int start = 0, end = down.size() - 1;

	while (end > start)
	{
		int mid = (start + end) / 2;
		
		if (currentFloor + 1 <= down[mid])
			end = mid;
		else
			start = mid + 1;
	}
	if (down[end] < currentFloor + 1)
		return 0;
	return (int)down.size() - end;
}

long long lowerBoundUp(int currentFloor, int length, int height)
{
	int start = 0, end = up.size() - 1;

	while (end > start)
	{
		int mid = (start + end) / 2;

		if (height - currentFloor <= up[mid])
			end = mid;
		else
			start = mid + 1;
	}
	if (up[end] < height - currentFloor)
		return 0;
	return (int)up.size() - end;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int n, h;
	cin >> n >> h;

	for (int i = 0; i < n; i++)
	{
		int value;
		cin >> value;
		if (i % 2 == 0)
			down.push_back(value);
		else
			up.push_back(value);
	}

	sort(down.begin(), down.end());
	sort(up.begin(), up.end());

	for (int i = 0; i < h; i++)
	{
		int downCount = lowerBoundDown(i, n);
		int upCount = lowerBoundUp(i, n, h);
		countEachFloor.push_back(downCount + upCount);
	}

	sort(countEachFloor.begin(), countEachFloor.end());

	int min = countEachFloor[0];
	int minCount = 0;
	for (int i = 0; i < countEachFloor.size(); i++)
	{
		if (countEachFloor[i] == min)
			minCount++;
		else
			break;
	}
	cout << min << ' ' << minCount;
}