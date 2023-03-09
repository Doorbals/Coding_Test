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
int dp[100001];
int n, d, c;
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
		if (dp[cur] < dist)	continue;
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

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		graph.clear();
		cin >> n >> d >> c;
		graph.resize(n + 1);
		for (int j = 0; j < d; j++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			graph[b].push_back(pii(c, a));
		}
		fill(dp, dp + 100001, INF);
		dijkstra(c);

		int count = 0, maxTime = 0;
		for (int j = 1; j <= n; j++)
		{
			if (dp[j] != INF)
			{
				count++;
				if(maxTime < dp[j])
					maxTime = dp[j];
			}
		}
		cout << count << ' ' << maxTime << endl;
	}
}
