#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <list>
#include <sstream>
#include <string>

using namespace std;	
vector<long long> lanLines;

long long binarySearch(int having, int need)
{
	long long start = 1, end = lanLines[having - 1];

	while (end >= start)
	{
		long long mid = (start + end) / 2;

		int count = 0;
		for (int j = 0; j < having; j++)
			count += lanLines[j] / mid;

		if (count < need)
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

	int k, n;
	cin >> k >> n;

	for (int i = 0; i < k; i++)
	{
		long long lan;
		cin >> lan;
		lanLines.push_back(lan);
	}
	sort(lanLines.begin(), lanLines.end());

	cout << binarySearch(k, n);

	return 0;
}