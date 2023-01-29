#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>

using namespace std;	
vector<string> dict;
vector<int> answer;

vector<int> solution(string msg)
{
	for (int i = 0; i < 26; i++)
	{
		string tmp = "";
		tmp.push_back(i + 'A');
		dict.push_back(tmp);
	}

	for (int i = 0; i < msg.size(); i++)
	{
		// 임시 문자열, 현재 순서 첫 글자 저장
		string tmp;
		tmp += msg[i];
		while (true)
		{
			auto it = find(dict.begin(), dict.end(), tmp);	// 지금까지 저장해 온 문자열 dict 내에서 find
			if (it != dict.end())	// dict에 있으면
			{
				i += 1;			// 다음 글자로 넘어가고  
				tmp += msg[i];	// 임시 문자열에 포함
			}
			else				// dict에 없으면
			{
				// 임시 문자열 마지막 글자 제외
				auto it_prev = find(dict.begin(), dict.end(), tmp.substr(0, tmp.size() - 1));
				answer.push_back(it_prev - dict.begin() + 1);
				i -= 1;		// 다시 이전 글자로 회귀
				dict.push_back(tmp);	// 없던 단어 dict에 저장
				break;
			}
		}
	}
	return answer;
}