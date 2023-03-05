#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <list>
using namespace std;

// 문자열을 각 연산자를 기준으로 나누어 숫자와 연산자로 저장
vector<string> split(string str)
{
	char dlim1 = '*', dlim2 = '+', dlim3 = '-';
	vector<string> result;
	int a, b, c;

	while (true)
	{
		a = find(str.begin(), str.end(), dlim1) - str.begin();
		b = find(str.begin(), str.end(), dlim2) - str.begin();
		c = find(str.begin(), str.end(), dlim3) - str.begin();

		if (a == str.size() && b == str.size() && c == str.size())
		{
			result.push_back(str);
			return result;
		}			
		else
		{
			int dlim = min({ a, b, c });
			result.push_back(str.substr(0, dlim));
			result.push_back(str.substr(dlim, 1));
			str = str.substr(dlim + 1, str.size() - dlim);
		}
	}
}

long long solution(string expression)
{
	// 연산자는 op, 숫자는 nums에 저장
	vector<string> v = split(expression);
	list<string> nums, op;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == "*" || v[i] == "+" || v[i] == "-")
			op.push_back(v[i]);
		else
			nums.push_back(v[i]);
	}

	vector<vector<string>> orders;
	orders.push_back({ "*", "+", "-" });
	orders.push_back({ "*", "-", "+" });
	orders.push_back({ "+", "*", "-" });
	orders.push_back({ "+", "-", "*" });
	orders.push_back({ "-", "+", "*" });
	orders.push_back({ "-", "*", "+" });

	vector<long long> result;
	for (int i = 0; i < orders.size(); i++)
	{
		list<string> numsCopy = nums, opCopy = op;
		for (int k = 0; k < 3; k++)
		{
			int j = 0;
			while(true)
			{
				if (j >= opCopy.size())
					break;

				auto it = opCopy.begin();				// 연산자 이터레이터
				advance(it, j);
				if (*it != orders[i][k])
				{
					j++;
					continue;
				}
					
				auto prevNumsIt = numsCopy.begin();		// 연산자 이전 글자 이터레이터
				auto postNumsIt = numsCopy.begin();		// 연산자 다음 글자 이터레이터
				advance(prevNumsIt, j);
				advance(postNumsIt, j + 1);

				if (*it == "*")
					*prevNumsIt = to_string(stoll(*prevNumsIt) * stoll(*postNumsIt));
				else if (*it == "+")
					*prevNumsIt = to_string(stoll(*prevNumsIt) + stoll(*postNumsIt));
				else
					*prevNumsIt = to_string(stoll(*prevNumsIt) - stoll(*postNumsIt));
				opCopy.erase(it);
				numsCopy.erase(postNumsIt);
				j = 0;
			}
		}
		result.push_back(stoll(*numsCopy.begin()));
	}

	long long maxValue = 0;
	for (int i = 0; i < result.size(); i++)
	{
		long long cur = llabs(result[i]);
		if (cur > maxValue)
			maxValue = cur;
	}
	return maxValue;
}