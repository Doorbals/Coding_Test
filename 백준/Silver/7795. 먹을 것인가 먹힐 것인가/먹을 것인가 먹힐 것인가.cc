#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> lefts;
vector<int> rights;

int lowerBound(int target)
{
	int start = 0, end = rights.size() - 1;

	while (end > start)
	{
		int mid = (start + end) / 2;

		if (target <= rights[mid])
			end = mid;
		else
			start = mid + 1;
	}

	if (target > rights[end])
		return rights.size();
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
		lefts.clear();
		rights.clear();
		int a, b, count = 0;
		cin >> a >> b;

		for (int j = 0; j < a; j++)
		{
			int num;
			cin >> num;
			lefts.push_back(num);
		}
		
		for (int j = 0; j < b; j++)
		{
			int num;
			cin >> num;
			rights.push_back(num);
		}

		sort(rights.begin(), rights.end());
		for (int j = 0; j < a; j++)
			count += lowerBound(lefts[j]);

		cout << count << endl;
	}
}