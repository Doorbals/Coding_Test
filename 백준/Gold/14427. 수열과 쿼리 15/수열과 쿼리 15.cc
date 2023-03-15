#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<long long, int> pli;

pli tree[400004];
long long datas[100001];
const long long INF = 1e9 + 1;
int n, m;

pli init(int start, int end, int node)
{
	if (start == end) return tree[node] = { datas[start], start };
	int mid = start + (end - start) / 2;
	return tree[node] = min(init(start, mid, node * 2), 
		init(mid + 1, end, node * 2 + 1));
}

pli findMin(int start, int end, int node, int left, int right)
{
	if (end < left || right < start) return { INF, 0 };
	if (left <= start && end <= right) return tree[node];
	int mid = start + (end - start) / 2;
	return min(findMin(start, mid, node * 2, left, right),
		findMin(mid + 1, end, node * 2 + 1, left, right));
}

pli update(int start, int end, int node, int index, long long dif)
{
	if (index < start || end < index) return tree[node];
	if (start == end) return tree[node] = { dif, start };
	int mid = start + (end - start) / 2;
	return tree[node] = min(update(start, mid, node * 2, index, dif),
		update(mid + 1, end, node * 2 + 1, index, dif));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> datas[i];

	init(1, n, 1);
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a;
		if (a == 1)
		{
			cin >> b >> c;
			update(1, n, 1, b, c);
		}
		else
			cout << findMin(1, n, 1, 1, n).second << '\n';
	}
}