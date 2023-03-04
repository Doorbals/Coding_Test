#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
typedef pair<int, int> pii;

int n, k;
int dp[100001];
const long long INF = 1e9;

pii move(int cur, int i)
{
	if (i == 0)
		return pii(cur - 1, 1);
	else if (i == 1)
		return pii(cur + 1, 1);
	else
		return pii(cur * 2, 0);
}

void dijkstra(int start)
{
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(pii(0, start));
	dp[start] = 0;

	while (!pq.empty())
	{
		int dist = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (dp[cur] < dist) continue;
		for (int i = 0; i < 3; i++)
		{
			pii curEdge = move(cur, i);
			int cost = dist + curEdge.second;
			if (curEdge.first >= 0 && curEdge.first <= 100000 && cost < dp[curEdge.first])
			{
				dp[curEdge.first] = cost;
				pq.push(pii(cost, curEdge.first));
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> k;
	fill(dp, dp + 100001, INF);
	dijkstra(n);
	cout << dp[k];
}