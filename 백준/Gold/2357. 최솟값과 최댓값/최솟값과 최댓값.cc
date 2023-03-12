#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
long long minTree[400004];
long long maxTree[400004];
long long datas[100001];
const long long INF = 1000000001;

long long minInit(int start, int end, int node)
{
	if (start == end) return minTree[node] = datas[start];
	int mid = start + (end - start) / 2;
	return minTree[node] = min(minInit(start, mid, node * 2), minInit(mid + 1, end, node * 2 + 1));
}

long long findMin(int start, int end, int node, int left, int right)
{
	if (end < left || right < start) return INF;
	if (left <= start && end <= right) return minTree[node];
	int mid = start + (end - start) / 2;
	return min(findMin(start, mid, node * 2, left, right), 
		findMin(mid + 1, end, node * 2 + 1, left, right));
}

long long maxInit(int start, int end, int node)
{
	if (start == end) return maxTree[node] = datas[start];
	int mid = start + (end - start) / 2;
	return maxTree[node] = max(maxInit(start, mid, node * 2), maxInit(mid + 1, end, node * 2 + 1));
}

long long findMax(int start, int end, int node, int left, int right)
{
	if (end < left || right < start) return 0;
	if (left <= start && end <= right) return maxTree[node];
	int mid = start + (end - start) / 2;
	return max(findMax(start, mid, node * 2, left, right),
		findMax(mid + 1, end, node * 2 + 1, left, right));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> datas[i];
	
	minInit(1, n, 1);
	maxInit(1, n, 1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a < b)
		{
			cout << findMin(1, n, 1, a, b) << ' ';
			cout << findMax(1, n, 1, a, b) << '\n';
		}
		else
		{
			cout << findMin(1, n, 1, b, a) << ' ';
			cout << findMax(1, n, 1, b, a) << '\n';
		}	
	}
}
