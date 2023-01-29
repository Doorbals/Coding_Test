#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <list>
#include <sstream>
#include <string>

using namespace std;	
vector<string> split1;
vector<vector<int>> split2;
vector<int> numCount(100000);
vector<int> answer;

vector<string> split(string input, char dlim)
{
	vector<string> result;
	stringstream ss;
	string stringBuffer;
	ss.str(input);
	while (getline(ss, stringBuffer, dlim))
	{
		result.push_back(stringBuffer);
	}
	return result;
}

vector<int> split_int(string input, char dlim)
{
	vector<int> result;
	stringstream ss;
	string stringBuffer;
	ss.str(input);
	while (getline(ss, stringBuffer, dlim))
	{
		result.push_back(stoi(stringBuffer));
	}
	return result;
}

bool compare(vector<int> v1, vector<int> v2)
{
	return v1.size() < v2.size();
}

vector<int> solution(string s)
{
	// '{' 삭제
	replace(s.begin(), s.end(), '{', ' ');
	s.erase(remove(s.begin(), s.end(), ' '), s.end());	// remove 하면 해당 문자가 삭제됐을 때의 문자열 길이 기준으로 마지막 위치 리턴함 						// -> s.erase(remove(), s.end())하면 삭제된 부분의 길이만큼 사이즈 줄어듦.

	// "},"을 "/"으로 교체 
	while (s.find("},") != string::npos)
		s.replace(s.find("},"), 2, "/");

	// '}' 삭제
	s.erase(remove(s.begin(), s.end(), '}'), s.end());
	
	// '/' 기준 split해서 벡터 각 원소로 저장
	split1 = split(s, '/');

	// 각 문자열 ',' 기준 split 해서 숫자로 변환해 저장
	split2.resize(split1.size());
	for (int i = 0; i < split1.size(); i++)
		split2[i] = split_int(split1[i], ',');

	// 숫자 개수 오름차순으로 정렬
	sort(split2.begin(), split2.end(), compare);

	// 각 숫자 개수 저장
	for (int i = 0; i < split2[split2.size() - 1].size(); i++)
		numCount[split2[split2.size() - 1][i]] += 1;

	// 튜플을 표현하는 집합 중 길이가 짧은 것부터 확인해 이전에 나오지 않은 수라면 answer 벡터에 추가시키고, 이전에 나온 숫자라면 넘어감.
	for (int i = 0; i < split2.size(); i++)
	{
		for (int j = 0; j < split2[i].size(); j++)
		{
			int currentNum = split2[i][j];
			if (numCount[currentNum] > 0)
			{
				answer.push_back(currentNum);
				numCount[currentNum]--;
			}
		}
	}

	return answer;
}