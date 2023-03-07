#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>
#include <string>
using namespace std;

long long tree[4000004];
long long datas[1000001];
int n, m;

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
	return sum(start, mid, node * 2, left, right)
		+ sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, int dif)
{
	if (index < start || index > end) return;
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

	cin >> n >> m;
	init(1, n, 1);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0)
		{
			if(b < c)
				cout << sum(1, n, 1, b, c) << "\n";
			else
				cout << sum(1, n, 1, c, b) << "\n";
		}
		else
		{
			long long calcNum =  c - datas[b];
			update(1, n, 1, b, calcNum);
			datas[b] = c;
		}
	}
}
