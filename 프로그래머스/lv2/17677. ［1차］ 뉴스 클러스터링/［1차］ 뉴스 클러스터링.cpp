#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>
#include <string>
#include <list>
using namespace std;

list<string> split(string str)
{
	list<string> splited;
	for (int i = 0; i < str.size() - 1; i++)
	{
		string substr = str.substr(i, 2);
		bool isAlpha = true;
		for (int i = 0; i < 2; i++)
		{
			if (!isalpha(substr[i]))
			{
				isAlpha = false;
				break;
			}
		}
		if(isAlpha)
			splited.push_back(str.substr(i, 2));
	}
	return splited;
}

int getIntersection(list<string> set1, list<string> set2)
{
	int count = 0;
	while (!set1.empty() && !set2.empty())
	{
		auto it_1 = set1.begin();
		auto it_2 = find(set2.begin(), set2.end(), *it_1);
		bool isAlpha = true;
		if (it_2 != set2.end())
		{
			set1.erase(it_1);
			set2.erase(it_2);
			count++;
		}
		else
			set1.erase(it_1);	
	}
	return count;
}

int getUnion(list<string> set1, list<string> set2)
{
	int count = 0;
	while (!set1.empty())
	{
		auto it_1 = set1.begin();
		auto it_2 = find(set2.begin(), set2.end(), *it_1);
		if (it_2 != set2.end())
		{
			set1.erase(it_1);
			set2.erase(it_2);
			count++;
		}
		else
		{
			set1.erase(it_1);
			count++;
		}
	}
	while (!set2.empty())
	{
		auto it = set2.begin();
		set2.erase(it);
		count++;
	}
	return count;
}

int solution(string str1, string str2) 
{
	for (int i = 0; i < str1.size(); i++)
		str1[i] = tolower(str1[i]);

	for (int i = 0; i < str2.size(); i++)
		str2[i] = tolower(str2[i]);

	list<string> set1 = split(str1);
	list<string> set2 = split(str2);

	int intersectionCnt, unionCnt;
	if (str1.size() > str2.size())
	{
		intersectionCnt = getIntersection(set1, set2);
		unionCnt = getUnion(set1, set2);
	}
	else
	{
		intersectionCnt = getIntersection(set2, set1);
		unionCnt = getUnion(set2, set1);
	}
		
	cout << intersectionCnt << ' ' << unionCnt << endl;
	if (intersectionCnt == 0 && unionCnt == 0)
		return 65536;
	else
		return (((double)intersectionCnt / (double)unionCnt) * 65536);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string str1, str2;
	str1 = "baa";
	str2 = "aaa";

	cout << solution(str1, str2);
}
