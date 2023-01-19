#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
vector<int> arr;
long long sum = 0;
long long half = 0;

int lowerBound(int n)		// 총합이 50을 처음 넘는 층을 구해야 하므로 lowerBound로 처리
{
	int start = 0, end = arr[arr.size() - 1], mid = 0;
	long long tmpSum = 0;

	while (start < end)
	{
		mid = (start + end) / 2;

		for (int i = 0; i < arr.size(); i++)	// 현재 층이 mid층 일 때
		{
			if (arr[i] >= mid)	
				tmpSum += mid;		// mid층 이상 컴퓨터 쌓여있는 칸은 mid 만큼 개수 더하기
			else
				tmpSum += arr[i];	// mid층보다 적게 깔려있는 칸은 해당 칸 총 개수 더하기
		}

		if (tmpSum >= half)			
			end = mid;
		else
			start = mid + 1;

		tmpSum = 0;
	}
	return end;
}

int main()
{
	int n;
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n * n; i++)
	{
		int num;
		cin >> num;
		arr.push_back(num);
		sum += num;
	}
	half = round(sum / 2.0);

	sort(arr.begin(), arr.end());

	cout << lowerBound(n);
}