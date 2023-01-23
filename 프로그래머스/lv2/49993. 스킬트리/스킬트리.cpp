#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;
vector<int> skillCheck(26, -1);

int solution(string skill, vector<string> skill_trees)
{
    int count = skill_trees.size();

    for (string str : skill_trees)
    {
        for (char ch : skill)
            skillCheck[ch - 'A'] = 0;
        for (char ch : str)
        {
            bool correct = true;
            for (int i = 0; i < skill.size(); i++)
            {
                if ((skill[i] != ch) && (skillCheck[skill[i] - 'A'] == 0) && (skillCheck[ch - 'A'] != -1))
                {
                    correct = false;
                    break;
                }
                else if (skill[i] == ch)
                    break;
            }
            skillCheck[ch - 'A'] = 1;
            if (!correct)
            {
                count--;
                break;
            }
        }
        skillCheck.assign(26, -1);
    }
    return count;
}