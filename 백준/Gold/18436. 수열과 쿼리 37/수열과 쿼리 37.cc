#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<long long, int> pii;	// 짝수, 홀수 개수

pii tree[400004];
int datas[100001];
int n, m;

pii init(int start, int end, int node)
{
	if (start == end)
	{
		if (datas[start] % 2 == 0)
			return tree[node] = pii(1, 0);
		else
			return tree[node] = pii(0, 1);
	}
	int mid = start + (end - start) / 2;
	pii leftNode = init(start, mid, node * 2);
	pii rightNode = init(mid + 1, end, node * 2 + 1);
	return tree[node] = pii(leftNode.first + rightNode.first,
		leftNode.second + rightNode.second);
}

pii get(int start, int end, int node, int left, int right)
{
	if (end < left || right < start) return pii(0, 0);
	if (left <= start && end <= right)
		return tree[node];
	int mid = start + (end - start) / 2;
	pii leftNode = get(start, mid, node * 2, left, right);
	pii rightNode = get(mid + 1, end, node * 2 + 1, left, right);
	return pii(leftNode.first + rightNode.first, leftNode.second + rightNode.second);
}

pii update(int start, int end, int node, int index, int dif)
{
	if (index < start || end < index) return tree[node];
	if (start == end)
	{
		if (dif % 2 == 0)
			return tree[node] = pii(1, 0);
		else
			return tree[node] = pii(0, 1);
	}
	int mid = start + (end - start) / 2;
	pii leftNode = update(start, mid, node * 2, index, dif);
	pii rightNode = update(mid + 1, end, node * 2 + 1, index, dif);
	return tree[node] = pii(leftNode.first + rightNode.first, leftNode.second + rightNode.second);
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
		else if (a == 2)
			cout << get(1, n, 1, b, c).first << '\n';
		else
			cout << get(1, n, 1, b, c).second << '\n';
	}
}
