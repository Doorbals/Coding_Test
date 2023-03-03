#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int n, m;
vector<vector<pii>> graph;
int dp[50001];
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
			int cost = dist + graph[cur][i].second;
			if (cost < dp[graph[cur][i].first])
			{
				dp[graph[cur][i].first] = cost;
				pq.push(pii(cost, graph[cur][i].first));
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;
	graph.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(pii(b, c));
		graph[b].push_back(pii(a, c));
	}

	fill(dp, dp + n + 1, INF);
	dijkstra(1);

	cout << dp[n];
}