#include <iostream>
#include <cmath>

using namespace std;
long long n;

long long binary_search()
{
	long long start = 1, end = sqrt(2 * n), mid;

	while (end >= start)
	{
		mid = start + (end - start) / 2;
		long long curLevel = ((mid * (mid + 1)) / 2);
		if (n > curLevel)
			start = mid + 1;
		else if (n == curLevel)
			return mid;
		else
			end = mid - 1;
	}
	return -1;
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		n = 0;
		scanf("%lld", &n);
		printf("#%d %lld\n", i + 1, binary_search());
	}
	return 0;
}