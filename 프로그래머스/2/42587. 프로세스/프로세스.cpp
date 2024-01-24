#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int findMax(vector<int>& v)
{
    int max = 0;
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] > max)
        {
            max = v[i];
        }
    }
    
    return max;
}

int solution(vector<int> priorities, int location) {
    int max = findMax(priorities);
    int count = 0;
    
    while(true)
    {
        for(int i = 0; i < priorities.size(); i++)
        {
            if(priorities[i] == max)
            {
                if(i == location)
                {
                    return ++count;
                }
                
                priorities[i] = 0;
                count++;
                max = findMax(priorities);
            }
        }
    }
    
    return count;
}