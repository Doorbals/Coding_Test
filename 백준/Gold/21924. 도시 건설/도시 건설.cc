#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>

using namespace std;
typedef pair<int, int> pii;

vector<vector<pii>> edges;
bool mst[100001] ;
long long answer = 0, sum = 0;

void prim(int n)
{
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	int i = 1, count = 1, loopCount = 0;
	
	while (count < n)
	{
		loopCount++;

		mst[i] = true;
		for (int j = 0; j < edges[i].size(); j++)
		{
			int curNode = edges[i][j].second;
			
			if (!mst[curNode])
				pq.push(edges[i][j]);
		}

		if (pq.empty())
		{
			sum = -1;
			answer = 0;
			return;
		}

		for (int k = 0; k < pq.size(); k++)
		{
			pii curEdge = pq.top();
			pq.pop();

			if (!mst[curEdge.second])
			{
				answer += curEdge.first;
				i = curEdge.second;
				count++;
				break;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int n, m;
	cin >> n >> m;

	edges.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back(pii(c, b));
		edges[b].push_back(pii(c, a));
		sum += c;		// 모든 간선 이을 때 간선 가중치의 총합
	}

	prim(n);
	cout << sum - answer;
}