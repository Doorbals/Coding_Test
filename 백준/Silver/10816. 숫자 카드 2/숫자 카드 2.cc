#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int arr[500000];

int lowerBound(int arr[], int start, int end, int target)
{
	int mid;

	while (end > start)
	{
		mid = (start + end) / 2;

		if (arr[mid] >= target)
			end = mid;
		else if (arr[mid] < target)
			start = mid + 1;
	}
	return end;
}

int upperBound(int arr[], int start, int end, int target)
{
	int mid;

	while (end > start)
	{
		mid = (start + end) / 2;

		if (arr[mid] > target)
			end = mid;
		else if(arr[mid] <= target)
			start = mid + 1;
	}
	return end;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		arr[i] = num;
	}

	sort(arr, arr + n);

	int m;
	cin >> m;

	string str;
	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		str += to_string(upperBound(arr, 0, n, num) - lowerBound(arr, 0, n, num)) + ' ';
	}

	cout << str;
	return 0;
}