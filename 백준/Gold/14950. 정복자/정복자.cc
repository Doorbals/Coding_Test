#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> tiii;

int parent[10001];
vector<tiii> edges;

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
	cin.tie(nullptr); cout.tie(nullptr);

	int n, m, t;
	cin >> n >> m >> t;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back(tiii(c, a, b));
		edges.push_back(tiii(c, b, a));
	}

	sort(edges.begin(), edges.end());
	for (int i = 1; i <= n; i++)
		parent[i] = i;

	int sum = 0;
	int count = 0;
	for (int i = 0; i < edges.size(); i++)
	{
		int curA = get<1>(edges[i]);
		int curB = get<2>(edges[i]);
	
		if (!findParent(curA, curB))
		{
			unionParent(curA, curB);
			sum += (count * t) + get<0>(edges[i]);
			count++;
		}
	}
	cout << sum;
}