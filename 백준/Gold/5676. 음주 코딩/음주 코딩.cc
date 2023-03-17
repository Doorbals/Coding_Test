#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char tree[400004];
int datas[100001];
int n, k;

char init(int start, int end, int node)
{
	if (start == end) 
	{
		if (datas[start] == 0) return tree[node] = '0';
		else if (datas[start] > 0) return tree[node] = '+';
		else return tree[node] = '-';
	}
	int mid = start + (end - start) / 2;
	char leftNode = init(start, mid, node * 2);
	char rightNode = init(mid + 1, end, node * 2 + 1);

	if (leftNode == '0' || rightNode == '0') return tree[node] = '0';
	else if (leftNode == rightNode) return tree[node] = '+';
	else return tree[node] = '-';
}

char mul(int start, int end, int node, int left, int right)
{
	if (end < left || right < start) return '+';
	if (left <= start && end <= right) return tree[node];
	int mid = start + (end - start) / 2;
	char leftNode = mul(start, mid, node * 2, left, right);
	char rightNode = mul(mid + 1, end, node * 2 + 1, left, right);

	if (leftNode == '0' || rightNode == '0') return '0';
	else if (leftNode == rightNode) return '+';
	else return '-';
}

char update(int start, int end, int node, int index, long long dif)
{
	if (index < start || end < index) return tree[node];
	if (start == end)
	{
		if (dif == 0) return tree[node] = '0';
		else if (dif > 0) return tree[node] = '+';
		else return tree[node] = '-';
	}
	int mid = start + (end - start) / 2;
	char leftNode = update(start, mid, node * 2, index, dif);
	char rightNode = update(mid + 1, end, node * 2 + 1, index, dif);

	if (leftNode == '0' || rightNode == '0') return tree[node] = '0';
	else if (leftNode == rightNode) return tree[node] = '+';
	else return tree[node] = '-';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	while (cin >> n >> k)
	{
		for (int i = 1; i <= n; i++)
			cin >> datas[i];

		init(1, n, 1);
		for (int i = 0; i < k; i++)
		{
			char a;
			int b, c;
			cin >> a >> b >> c;
			if (a == 'C')
			{
				update(1, n, 1, b, c);
				datas[b] = c;
			}
			else
				cout << mul(1, n, 1, b, c);
		}
		cout << '\n';
	}
}
