#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void solution(int tc, int n, int m)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if ((m >> i) & 1)
			count++;
	}
	cout << '#' << tc << ' ' << (count == n ? "ON" : "OFF") << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int tc, n, m;
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		cin >> n >> m;
		solution(i + 1, n, m);
	}
} 