#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>

using namespace std;
typedef tuple<int, int, int> tiii;
vector<tiii> edges;
vector<int> parent;

int getParent(int n)
{
	if (parent[n] == n) 
		return n;
	else
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
	cin.tie(nullptr); cout.tie(nullptr);

	while (true)
	{
		int n, m, max = 0;
		cin >> n >> m;

		if (n == 0 && m == 0)
			break;

		for (int i = 0; i < m; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			edges.push_back(tiii(c, a, b));
			max += c;
		}

		for (int i = 0; i < n; i++)
			parent.push_back(i);

		sort(edges.begin(), edges.end());

		int answer = 0;
		for (int i = 0; i < m; i++)
		{
			int curA = get<1>(edges[i]);
			int curB = get<2>(edges[i]);

			if (!findParent(curA, curB))
			{
				unionParent(curA, curB);
				answer += get<0>(edges[i]);
			}
		}
		cout << max - answer << endl;
		edges.clear();
		parent.clear();
	}	
}