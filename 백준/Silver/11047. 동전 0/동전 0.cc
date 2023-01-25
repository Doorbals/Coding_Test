#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int solution(vector<int> value, int k)
{
	int count = 0;
	for (int i = value.size() - 1; i >= 0; i--)
	{
		count += k / value[i];
		k %= value[i];
	}
	return count;
}

int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int n, k;
	cin >> n >> k;

	vector<int> value;
	for (int i = 0; i < n; i++)
	{
		int v;
		cin >> v;
		value.push_back(v);
	}
		
	cout << solution(value, k);
}