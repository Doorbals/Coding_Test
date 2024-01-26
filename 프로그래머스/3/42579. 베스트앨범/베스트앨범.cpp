#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

bool sicmp(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

bool iicmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first != b.first)
	{
		return a.first > b.first;
	}
	else
	{
		return a.second < b.second;
	}
}

vector<int> solution(vector<string> genres, vector<int> plays) 
{
	vector<int> answer;
	vector<string> genreRank; 
	map<string, int> totalPlays;   
	multimap<string, pair<int, int>> playsByGenre;

	for (int i = 0; i < genres.size(); i++)
	{
		totalPlays[genres[i]] += plays[i];
		playsByGenre.insert(make_pair(genres[i], make_pair(plays[i], i)));
	}
    
    vector<pair<string, int>> temp(totalPlays.begin(), totalPlays.end());
    sort(temp.begin(), temp.end(), sicmp);

	for (auto it = temp.begin(); it != temp.end(); ++it)
	{
		genreRank.push_back(it->first);
	}

	for (int i = 0; i < genreRank.size(); i++)
	{
		vector<pair<int, int>> curGenre;
		auto beginIt = playsByGenre.lower_bound(genreRank[i]);
		auto endIt = playsByGenre.upper_bound(genreRank[i]);

		for (auto it = beginIt; it != endIt; ++it)
		{
			curGenre.push_back(it->second);
		}
        
        if(curGenre.size() == 1)
        {
            answer.push_back(curGenre[0].second);
        }
        else
        {
            sort(curGenre.begin(), curGenre.end(), iicmp);
            answer.push_back(curGenre[0].second);
            answer.push_back(curGenre[1].second);
        }
	}

	return answer;
}