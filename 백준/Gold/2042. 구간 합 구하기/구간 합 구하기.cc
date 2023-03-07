#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>
#include <string>
#include <list>
using namespace std;

int n, m, k;
long long tree[4000004];	// 데이터 크기에 4를 곱함
long long datas[1000001];

long long init(int start, int end, int node)
{
	if (start == end) return tree[node] = datas[start];
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

long long sum(int start, int end, int node, int left, int right)
{
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) +
		sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, long long dif)
{
	if (start > index || end < index)	return;
	tree[node] += dif;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, dif);
	update(mid + 1, end, node * 2 + 1, index, dif);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> datas[i];

	init(0, n - 1, 1);
	for (int i = 0; i < m + k; i++)
	{
		long long a, b, c;
		cin >> a >> b >> c;

		if (a == 1)
		{
			long long calcNum = c - datas[b - 1];
			update(0, n - 1, 1, b - 1, calcNum);
			datas[b - 1] = c;
		}
		else
			cout << sum(0, n - 1, 1, b - 1, c - 1) << "\n";
	}
}
