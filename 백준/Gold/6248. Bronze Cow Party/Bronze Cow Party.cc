#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;
typedef pair<int, int> pii;

int n, m, x;
vector<vector<pii>> graph;
int dp[1001];
const long long INF = 1e9;

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
		for (int i = 0; i < graph[cur].size(); i++)
		{
			pii curEdge = graph[cur][i];
			int cost = dist + curEdge.second;
			if (cost < dp[curEdge.first])
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

	cin >> n >> m >> x;
	graph.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(pii(b, c));
		graph[b].push_back(pii(a, c));
	}

	fill(dp, dp + n + 1, INF);
	dijkstra(x);

	int maxValue = 0;
	for (int i = 1; i <= n; i++)
	{
		if (maxValue < dp[i])
			maxValue = dp[i];
	}
	cout << maxValue * 2;
}
