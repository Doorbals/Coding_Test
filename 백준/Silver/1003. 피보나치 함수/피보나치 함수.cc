#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>
using namespace std;

int n;
int target;
int dp_0[41];		
int dp_1[41];		

void solution()
{
	dp_0[0] = 1, dp_1[0] = 0;
	dp_0[1] = 0, dp_1[1] = 1;

	for (int i = 2; i <= target; i++)
	{
		dp_0[i] = dp_0[i - 1] + dp_0[i - 2];
		dp_1[i] = dp_1[i - 1] + dp_1[i - 2];
    }
	cout << dp_0[target] << ' ' << dp_1[target];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> target;
		solution();
		cout << endl;
	}
}