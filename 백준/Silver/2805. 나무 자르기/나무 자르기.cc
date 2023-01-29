#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>

using namespace std;
vector<long long> trees;

long long binarySearch(long long n)
{
	long long start = 0, end = trees[trees.size() - 1] - 1;

	while (end >= start)
	{
		long long sum = 0;
		long long mid = (start + end) / 2;
		for (int i = 0; i < trees.size(); i++)
		{
			if(trees[i] - mid > 0)
				sum += (trees[i] - mid);
		}
			
		if (sum < n)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return end;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int n;
	long long m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		long long height;
		cin >> height;
		trees.push_back(height);
	}
	sort(trees.begin(), trees.end());

	cout << binarySearch(m);

	return 0;
}