#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	set<string> s;
	map<string, int> info;
	vector<string> answer;

	string name;
	for (int i = 0; i < n; i++)
	{
		cin >> name;
		++info[name];
	}

	for (int i = 0; i < m; i++)
	{
		cin >> name;
		++info[name];
	}

	for (auto it = info.begin(); it != info.end(); ++it)
	{
		if (it->second == 2)
		{
			answer.push_back(it->first);
		}
	}

	sort(answer.begin(), answer.end());
	cout << answer.size() << endl;
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << endl;
	}
}