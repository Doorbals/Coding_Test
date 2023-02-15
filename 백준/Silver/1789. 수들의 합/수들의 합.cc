#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	long long n, sum = 0;
	int count = 0;
	cin >> n;

	long long i = 1;
	while (true)
	{
		sum += i;
		count++;
		i++;
		if (sum > n)
		{
			count -= 1;
			break;
		}
	}
	cout << count;
}