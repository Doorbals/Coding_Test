#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>

using namespace std;
typedef tuple<float, int, int> tfii;
typedef pair<float, float> pff;

int parent[100];

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

int findParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);

	return (a == b);
}

vector<pff> nodes;

float calcDist(pff a, pff b)
{
	return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		float x, y;
		cin >> x >> y;
		nodes.push_back(pff(x, y));
	}

	vector<tfii> edges;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				float cost = calcDist(nodes[i], nodes[j]);
				edges.push_back(tfii(cost, i, j));
			}
		}
	}

	for (int i = 0; i < n; i++)
		parent[i] = i;

	sort(edges.begin(), edges.end());

	float answer = 0;
	for (int i = 0; i < edges.size(); i++)
	{
		int curA = get<1>(edges[i]);
		int curB = get<2>(edges[i]);

		if (!findParent(curA, curB))
		{
			unionParent(curA, curB);
			answer += get<0>(edges[i]);
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << answer;
}