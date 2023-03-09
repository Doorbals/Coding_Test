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
int dp[20001];
const long long INF = 1e9;
int v, e, k;

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
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> v >> e >> k;
	graph.resize(v + 1);
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(pii(c, b));
	}
	fill(dp, dp + v + 1, INF);
	dijkstra(k);
	for (int i = 1; i <= v; i++)
	{
		if (dp[i] == INF)
			cout << "INF" << '\n';
		else
			cout << dp[i] << '\n';
	}
	
}
