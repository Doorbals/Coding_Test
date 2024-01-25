#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int totalSize = prices.size();
    vector<int> answer;
    answer.resize(totalSize);
    
    // 가격 / 위치 저장
    stack<pair<int, int>> s;
    s.push(make_pair(prices[0], 0));

    for(int i = 1; i < totalSize; i++)
    {
        
        while(!s.empty())
        {
            pair<int, int> top = s.top();
            if(top.first > prices[i])
            {
                answer[top.second] = i - top.second;
                s.pop();
                top = s.top();
            }
            else
            {
                break;
            }
        }
        
        s.push(make_pair(prices[i], i));
    }
   
    while(!s.empty())
    {
        pair<int, int> top = s.top();
        answer[top.second] = (totalSize - 1) - top.second;
        s.pop();
    }

    return answer;
}