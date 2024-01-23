#include <string>
#include <iostream>
#include <queue>

using namespace std;

bool solution(string s)
{
	queue<char> q;
	for (int i = 0; i < s.length(); ++i)
	{
		q.push(s[i]);
	}

	int count = 0;
	while (!q.empty())
	{
		char c = q.front();
		q.pop();

		if (c == '(')
		{
			++count;
		}
		else
		{
			--count;
		}

		if (count < 0)
		{
			return false;
		}
	}

    if(count != 0)
    {
        return false;
    }
        
	return true;
}