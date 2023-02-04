#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>

using namespace std;
typedef tuple<int, int, int> tiii;

int parent[1001];

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
		parent[a] = b;
	else
		parent[b] = a;
}

int findParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);

	return (a == b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int n, m, k;
	cin >> n >> m >> k;

	vector<tiii> edges;
	for (int i = 0; i < m; i++)
	{
		int a, b, c = i + 1;
		cin >> a >> b;
		edges.push_back(tiii(c, a, b));
	}
	sort(edges.begin(), edges.end());

	for (int i = 0; i < k; i++)
	{
		int answer = 0, count = 0;
		for (int i = 0; i <= n; i++)
			parent[i] = i;

		for (int i = 0; i < edges.size(); i++)
		{
			int curA = get<1>(edges[i]);
			int curB = get<2>(edges[i]);

			if (!findParent(curA, curB))
			{
				unionParent(curA, curB);
				answer += get<0>(edges[i]);
				count++;
			}
		}

		if(count == n - 1)
			cout << answer << ' ';
		else
			cout << 0 << ' ';

		edges.assign(edges.begin() + 1, edges.end());
	}
}