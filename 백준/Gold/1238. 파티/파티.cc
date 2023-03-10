#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>
#include <string>
#include <list>
using namespace std;
typedef pair<int, int> pii;

vector<vector<pii>> graph;
vector<vector<pii>> reverse_graph;
int dp[1001];
int result[1001];
int n, m, x;
const long long INF = 1e9;

void dijkstra(int start, bool reverse)
{
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(pii(0, start));
	dp[start] = 0;
	while (!pq.empty())
	{
		int dist = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (dp[cur] < dist)	continue;
		if (!reverse)
		{
			for (int i = 0; i < graph[cur].size(); i++)
			{
				pii curEdge = graph[cur][i];
				int cost = dist + curEdge.first;
				if (cost < dp[curEdge.second])
				{
					dp[curEdge.second] = cost;
					pq.push(pii(cost, curEdge.second));
				}
			}
		}
		else
		{
			for (int i = 0; i < reverse_graph[cur].size(); i++)
			{
				pii curEdge = reverse_graph[cur][i];
				int cost = dist + curEdge.first;
				if (cost < dp[curEdge.second])
				{
					dp[curEdge.second] = cost;
					pq.push(pii(cost, curEdge.second));
				}
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
	reverse_graph.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(pii(c, b));
		reverse_graph[b].push_back(pii(c, a));
	}

	// 1 ~ n 도시부터 x 도시까지의 거리 구하기
	fill(dp, dp + n + 1, INF);
	dijkstra(x, true);
	for (int i = 1; i <= n; i++)
		result[i] += dp[i];

	// x 도시부터 1 ~ n 도시까지의 거리 구하기
	fill(dp, dp + n + 1, INF);
	dijkstra(x, false);
	for (int i = 1; i <= n; i++)
		result[i] += dp[i];

	int maxTime = 0;
	for (int i = 1; i <= n; i++)
	{
		if (maxTime < result[i])
			maxTime = result[i];
	}
	cout << maxTime;
}
