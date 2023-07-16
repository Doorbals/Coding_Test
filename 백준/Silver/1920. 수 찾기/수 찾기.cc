#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

int binarySearch(vector<int>& arr, int target, int start, int end)
{
	while (end >= start)
	{
		int mid = start + (end - start) / 2;

		if (target == arr[mid]) return mid;
		else if (target < arr[mid]) end = mid - 1;
		else start = mid + 1;
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> nums;

	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		nums.push_back(m);
	}
    
	sort(nums.begin(), nums.end());
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		if (binarySearch(nums, m, 0, n) != -1)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
}