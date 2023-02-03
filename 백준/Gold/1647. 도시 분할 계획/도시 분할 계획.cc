#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>

using namespace std;
typedef tuple<int, int, int> tiii;

int parent[100001];

int getParent(int n)
{
	if (parent[n] == n) return n;
	return parent[n] = getParent(parent[n]);
}

void unionParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

bool findParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);

	return (a == b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();


	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i <= n; i++)
		parent[i] = i;
	
	vector<tiii> edges;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back(tiii(c, a, b));
	}
	sort(edges.begin(), edges.end());
	
	long long answer = 0;
	int maxCost = 0;

	for (int i = 0; i < edges.size(); i++)
	{
		int curA = get<1>(edges[i]);
		int curB = get<2>(edges[i]);
		int curC = get<0>(edges[i]);

		if (!findParent(curA, curB))
		{
			unionParent(curA, curB);
			answer += curC;

			if (curC > maxCost)
				maxCost = curC;
		}
	}
	cout << answer - maxCost;
}