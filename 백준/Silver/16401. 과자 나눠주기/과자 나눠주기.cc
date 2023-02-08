#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>

using namespace std;
vector<long long> snacks;
long long maxLen = 0;

long long binary_search(int m, int n)
{
	long long start = 1, end = maxLen, answer = 0;

	while (end >= start)
	{
		long long mid = start + (end - start) / 2;
		long long count = 0;
		for (int i = 0; i < n; i++)
			count += snacks[i] / mid;

		if (count < m)		// 너무 크게 잘라서 조카 인원 수 충족 X -> 해당 길이 이상 값은 탐색 필요 X
			end = mid - 1;
		else				// 딱 맞게 자르거나 너무 작게 잘라서 조카 인원수 충족 O -> 해당 길이 미만 값은 탐색 필요 X -> 현재 mid를 정답으로 설정해놓고, 초과 값 탐색.
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
		long long len;
		cin >> len;
		snacks.push_back(len);
		if (maxLen < len)
			maxLen = len;
	}

	cout << binary_search(m, n);
}