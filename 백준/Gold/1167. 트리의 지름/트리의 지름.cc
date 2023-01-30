#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <list>
#include <sstream>
#include <string>

using namespace std;	
typedef pair<int, int> pii;
vector<vector<pii>> nodes;

vector<long long> dists;
vector<long long> dists_temp;
long long maxDis = 0;
int farthestNode;

void dfs(int currentNode, long long currentDist)
{
	dists[currentNode] = currentDist;
	if (maxDis < currentDist)
	{
		maxDis = currentDist;
		farthestNode = currentNode;
	}

	for (int i = 0; i < nodes[currentNode].size(); i++)
	{
		pii nearNode = nodes[currentNode][i];
		if (dists[nearNode.first] == -1)
			dfs(nearNode.first, currentDist + nearNode.second);
	}
}

int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int n;
	cin >> n;
	nodes.resize(n);
	for (int i = 0; i < n; i++)
	{
		int node = 0, near = 0, dist = 0;
		cin >> node;
		while (true)
		{
			cin >> near;
			if (near == -1)
				break;
			cin >> dist;
			
			nodes[node - 1].push_back(pii(near - 1, dist));
		}
	}
	dists.assign(n, -1);
	dfs(0, 0);

	int node1 = farthestNode;
	dists_temp = dists;

	dists.assign(n, -1);
	maxDis = 0;
	dfs(node1, 0);
	cout << maxDis;

	return 0;
}