#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>

using namespace std;
vector<int> snacks;
int maxLen = 0;

int binary_search(int m, int n)
{
	int start = 1, end = maxLen, answer = 0;

	while (end >= start)
	{
		int mid = start + (end - start) / 2;
		int count = 0;
		for (int i = 0; i < n; i++)
			count += snacks[i] / mid;

		if (count < m)		
			end = mid - 1;
		else				
		{
			answer = mid;
			start = mid + 1;
		}
	}
	return answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int m, n;
	cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		int len;
		cin >> len;
		snacks.push_back(len);
		if (maxLen < len)
			maxLen = len;
	}
	cout << binary_search(m, n);
}