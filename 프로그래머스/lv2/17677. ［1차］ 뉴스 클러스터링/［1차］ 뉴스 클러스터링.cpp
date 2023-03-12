#include <iostream>
#include <algorithm>
#include <string>
#include <list>
using namespace std;

// 문자열을 두 글자씩 끊어서 다중 집합 만들기 (특수 문자 들어간 집합 제외)
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

// 교집합과 합집합의 수 세기
pair<int, int> countSet(list<string> set1, list<string> set2)
{
	int intersectionCnt = 0, unionCnt = 0;
	while (!set1.empty())
	{
		auto it_1 = set1.begin();
		auto it_2 = find(set2.begin(), set2.end(), *it_1);
		if (it_2 != set2.end())
		{
			set1.erase(it_1);
			set2.erase(it_2);
			intersectionCnt++;
			unionCnt++;
		}
		else
		{
			set1.erase(it_1);
			unionCnt++;
		}
	}
	while (!set2.empty())
	{
		auto it = set2.begin();
		set2.erase(it);
		unionCnt++;
	}
	return {intersectionCnt, unionCnt};
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
	pair<int, int> result;
	if (str1.size() > str2.size())
		result = countSet(set1, set2);
	else
		result = countSet(set2, set1);
	intersectionCnt = result.first;
	unionCnt = result.second;
		
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
	str1 = "FRANCE";
	str2 = "french";

	cout << solution(str1, str2);
}
