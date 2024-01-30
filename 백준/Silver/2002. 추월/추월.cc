#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> cars;
vector<bool> check;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int n, count;
	cin >> n;
	count = 0;

	string inCarNumber;
	for (int i = 0; i < n; i++)
	{
		cin >> inCarNumber;
		cars[inCarNumber] = i;
		check.push_back(false);
	}

	string outCarNumber;
	for (int i = 0; i < n; i++)
	{
		cin >> outCarNumber;
		int cur = cars[outCarNumber];

		bool result = true;
		for (int j = 0; j < cur; j++)
		{
			if (!check[j])
			{
				result = false;
				break;
			}
		}
		
		if(!result)
		{
			count++;
		}

		check[cur] = true;
	}
	
	cout << count;
	return 0;
}