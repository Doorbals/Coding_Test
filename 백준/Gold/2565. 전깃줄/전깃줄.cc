#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int n;
vector<pii> edges;	// 전선의 시작 번호, 끝 번호 저장
int dp[101];

int solution()
{
	int maxCount = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (edges[j].second < edges[i].second && dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j] + 1;

				if (maxCount < dp[i])
					maxCount = dp[i];
			}
		}
	}
	return n - maxCount;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	edges.push_back(pii(0, 0));
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		edges.push_back(pii(a, b));
		dp[i] = 1;
	}
	sort(edges.begin(), edges.end());
	cout << solution();
}