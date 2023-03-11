#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k;
long long tree[4000004];
long long datas[1000001];
const long long MOD = 1000000007;

// 구간곱 트리 초기화
long long init(int start, int end, int node)
{
	if (start == end) return tree[node] = datas[start];
	int mid = start + (end - start) / 2;
	return tree[node] = (init(start, mid, node * 2) * init(mid + 1, end, node * 2 + 1)) % MOD;
}

// 구간곱 구하기
long long mul(int start, int end, int node, int left, int right)
{
	if (end < left || right < start) return 1;
	if (left <= start && end <= right) return tree[node];
	int mid = start + (end - start) / 2;
	return (mul(start, mid, node * 2, left, right)
		* mul(mid + 1, end, node * 2 + 1, left, right)) % MOD;
}

// 특정 노드 값 수정
// 구간합과 달리 특정 노드의 값이 0으로 바뀌거나, 0에서 다른 값으로 바뀔 때 상위 노드부터 계산해 값을 수정할 수 없다. 
// 따라서 init()과 같이 하위 노드 값부터 상위 노드로 바뀌는 방식으로 진행한다.
long long update(int start, int end, int node, int index, long long dif)
{
	if (index < start || end < index) return tree[node];
	if (start == end) return tree[node] = dif;	// index가 현재 구간에 들어오고, 구간 내에 수가 하나 뿐이다 -> 해당 수가 바꾸고자 하는 수이므로 해당 노드 값 변경 
	int mid = start + (end - start) / 2;
	return tree[node] = (update(start, mid, node * 2, index, dif) * update(mid + 1, end, node * 2 + 1, index, dif)) % MOD;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		cin >> datas[i];

	init(1, n, 1);
	for (int i = 0; i < m + k; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			update(1, n, 1, b, c);
			datas[b] = c;
		}
		else
			cout << mul(1, n, 1, b, c) << '\n';
	}
}
