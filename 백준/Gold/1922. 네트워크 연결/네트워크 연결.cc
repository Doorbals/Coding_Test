#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

vector<vector<pii>> edges;
bool mst[1001];
int minCost = 0;

void prim(int n)
{
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	int i = 1, count = 1;

	while (count < n)
	{
		mst[i] = true;

		for (int j = 0; j < edges[i].size(); j++)
		{
			int curNode = edges[i][j].second;
			if (!mst[curNode])
				pq.push(edges[i][j]);
		}
		
		for (int k = 0; k < pq.size(); k++)
		{
			pii curEdge = pq.top();
			pq.pop();
			if (!mst[curEdge.second])
			{
				i = curEdge.second;
				minCost += curEdge.first;
				count++;
				break;
			}
		}
	}
	return;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int n, m;
	cin >> n >> m;

	edges.resize(n * 2);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		edges[a].push_back(pii(c, b));
		edges[b].push_back(pii(c, a));
	}
	prim(n);
	cout << minCost;
}