// 크루스칼 알고리즘 파일 주석 확인하면 자세히 알 수 있음.
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> tiii;

int parent[10001];

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

	vector<tiii> edges;

	int v, e, sum = 0;
	cin >> v >> e;

	for (int i = 0; i < v; i++)
		parent[i] = i;

	for (int i = 0; i < e; i++)
	{
		int a, b, v;
		cin >> a >> b >> v;
		edges.push_back(tiii(v, a, b));
	}

	sort(edges.begin(), edges.end());

	for (int i = 0; i < edges.size(); i++)
	{
		int curA = get<1>(edges[i]);
		int curB = get<2>(edges[i]);
		if (!findParent(curA, curB))
		{
			unionParent(curA, curB);
			sum += get<0>(edges[i]);
		}
	}
	cout << sum;
}