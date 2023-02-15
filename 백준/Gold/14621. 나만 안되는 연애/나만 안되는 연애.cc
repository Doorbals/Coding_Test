#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>

using namespace std;
typedef pair<int, int> pii;
vector<vector<pii>> edges;	// 각 노드에 연결된 간선들에 대한 정보 (거리, 상대 노드) 저장 
vector<char> mORn;			// 남대인지 여대인지 저장
bool mst[1001];				// mst에 포함되어있는지 여부
int n, m;

int prim()
{
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	int i = 1, answer = 0, count = 1;

	while(count < n)
	{
		mst[i] = true;

		for (int j = 0; j < edges[i].size(); j++)
		{
			pii curEdge = edges[i][j];
			if (!mst[curEdge.second] && mORn[curEdge.second] != mORn[i])
				pq.push(curEdge);
		}

		if (pq.size() == 0)
			return -1;

		for (int j = 0; j < pq.size(); j++)
		{
			pii curEdge = pq.top();
			pq.pop();
			if (!mst[curEdge.second])
			{
				i = curEdge.second;
				answer += curEdge.first;
				count++;
				break;
			}
		}
	}
	return answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;

	mORn.resize(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> mORn[i];
	
	edges.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back(pii(c, b));
		edges[b].push_back(pii(c, a));
	}
	
	cout << prim();
}