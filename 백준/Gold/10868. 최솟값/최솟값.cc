#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
long long tree[400004];
long long datas[100001];
const long long INF = 1000000001;

long long init(int start, int end, int node)
{
	if (start == end) return tree[node] = datas[start];
	int mid = start + (end - start) / 2;
	return tree[node] = min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

long long findMin(int start, int end, int node, int left, int right)
{
	if (end < left || right < start) return INF;
	if (left <= start && end <= right) return tree[node];
	int mid = start + (end - start) / 2;
	return min(findMin(start, mid, node * 2, left, right), 
		findMin(mid + 1, end, node * 2 + 1, left, right));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> datas[i];
	
	init(1, n, 1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		if(a < b)
			cout << findMin(1, n, 1, a, b) << '\n';
		else
			cout << findMin(1, n, 1, b, a) << '\n';
	}
}
