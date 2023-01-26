#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <list>
#include <sstream>
#include <string>

using namespace std;
typedef pair<int, int> pii;

bool Compare(pii confA, pii confB)
{
	if (confA.first == confB.first)
		return confA.second < confB.second;
	else
		return confA.first < confB.first;
}

int solution(vector<pii> confs)
{
	int count = 0;
	int start = 0, end = 0;
	for (int i = 0; i < confs.size(); i++)
	{
		if (confs[i].first < end)
		{
			if (confs[i].second <= end)
			{
				start = confs[i].first;
				end = confs[i].second;
			}
		}
		else if (confs[i].first >= end)
		{
			count++;
			start = confs[i].first;
			end = confs[i].second;
		}
	}
	return count;
}

int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int n;
	cin >> n;

	vector<pii> conferences;
	for (int i = 0; i < n; i++)
	{
		int start, end;
		cin >> start >> end;

		conferences.push_back(pii(start, end));
	}

	sort(conferences.begin(), conferences.end(), Compare);

	cout << solution(conferences);
}