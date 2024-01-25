#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	map<string, int> m;
    
    for(int i = 0; i < completion.size(); i++)
    {
        m[completion[i]] += 1;
    }
    
    for(int i = 0; i < participant.size(); i++)
    {
        if(m.find(participant[i]) == m.end())
        {
            return participant[i];
        }
        else
        {
            if(m[participant[i]] <= 0)
            {
                return participant[i];
            }
            else
            {
                m[participant[i]] -= 1;
            }
        }
    }
}