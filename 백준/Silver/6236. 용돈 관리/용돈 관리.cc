#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>

using namespace std;
vector<int> fees;
long long totalSum = 0;

long long binarySearch(int n)
{
	int start = 1, end = totalSum;
	long long answer = 0;

	while (end >= start)
	{
		long long mid = (start + end) / 2;
		int count = 1;
		long long tmp = 0;
		for (int i = 0; i < fees.size(); i++)
		{
			tmp += fees[i];
			if (tmp > mid)
			{
				count++;
				i--;
				tmp = 0;
				if (count > n)
					break;
			}
		}

		if (count <= n)		// count가 n보다 작거나 같음 : 최소 금액을 너무 크게 잡았거나 딱 맞게 잡음
		{
			answer = mid;
			end = mid - 1;
		}
		else				// count가 n보다 큼 : 최소 금액을 너무 작게 잡음
		{
			start = mid + 1;
		}
	}
	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int f;
		cin >> f;
		fees.push_back(f);
		totalSum += f;
	}

	cout << binarySearch(m);
	return 0;
}