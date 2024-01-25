#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    answer.resize(prices.size(), -1);
    
    for(int i = 0; i < prices.size(); i++)
    {
        for(int j = i + 1; j < prices.size(); j++)
        {
            if(prices[j] < prices[i])
            {
                answer[i] = j - i;
                break;
            }
        }
        
        if(answer[i] == -1)
        {
            answer[i] = (prices.size() - 1) - i;
        }
    }
    
    return answer;
}