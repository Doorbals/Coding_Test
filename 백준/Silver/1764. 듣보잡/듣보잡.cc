#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	set<string> s;
	vector<string> answer;

	for (int i = 0; i < n; i++)
	{
		string name;
		cin >> name;
		s.insert(name);
	}

	for (int i = 0; i < m; i++)
	{
		string name;
		cin >> name;
		set<string>::iterator findIt = s.find(name);
		if (findIt != s.end())
		{
			answer.push_back(name);
		}
	}

	sort(answer.begin(), answer.end());
	cout << answer.size() << '\n';
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << '\n';
	}
}