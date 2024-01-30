#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> pocketmonMap;
vector<string> pocketmonVec;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int n, m;
	cin >> n >> m;

	string name;
	for (int i = 0; i < n; i++)
	{
		cin >> name;
		pocketmonMap[name] = i;
		pocketmonVec.push_back(name);
	}

	string q;
	for (int i = 0; i < m; i++)
	{
		cin >> q;
		if (isdigit(q[0]) == 0)
		{
			cout << pocketmonMap[q] + 1 << '\n';
		}
		else
		{
			cout << pocketmonVec[stoi(q) - 1] << '\n';
		}
	}

	return 0;
}