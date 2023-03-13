#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long tree[400004];
long long datas[100001];
int n, m;
const int INF = 1e9;

long long init(int start, int end, int node)
{
	if (start == end) return tree[node] = datas[start];
	int mid = start + (end - start) / 2;
	return tree[node] = min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

long long minValue(int start, int end, int node, int left, int right)
{
	if (end < left || right < start) return INF;
	if (left <= start && end <= right) return tree[node];
	int mid = start + (end - start) / 2;
	return min(minValue(start, mid, node * 2, left, right), 
		minValue(mid + 1, end, node * 2 + 1, left, right));
}

long long update(int start, int end, int node, int index, long long dif)
{
	if (index < start || end < index) return tree[node];
	if (start == end) return tree[node] = dif;
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
		cin >> a >> b >> c;
		if (a == 1)
		{
			update(1, n, 1, b, c);
			datas[b] = c;
		}
		else
		{
			cout << minValue(1, n, 1, b, c) << '\n';
		}
	}
}
