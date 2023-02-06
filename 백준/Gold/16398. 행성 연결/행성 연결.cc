#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>

using namespace std;
typedef pair<int, int> pii;

bool mst[1001];
vector<vector<pii>> edges;
long long answer = 0;

void prim(int n)
{
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	int i = 0, count = 1;

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
				answer += curEdge.first;
				count++;
				i = curEdge.second;
				break;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int n;
	cin >> n;

	edges.resize(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int c;
			cin >> c;
			edges[i].push_back(pii(c, j));
		}
	}

	prim(n);
	cout << answer;
}