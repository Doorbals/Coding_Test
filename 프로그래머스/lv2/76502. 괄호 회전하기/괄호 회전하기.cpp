#include <string>
#include <vector>

using namespace std;

int bracket1 = 0, bracket2 = 0, bracket3 = 0; // 각 괄호의 스택을 표시하는 정수. 음수로 떨어지면 안됨. 여는 괄호일 때 +1, 닫는 괄호일 때 -1, 
                                              // 문자열 전체 돌았을 때 최종적으로 모든 스택이 0이 되어야 함.

int CheckString(string s) 
{   
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '[')
        {   
            bracket1 += 1;

            // 현재 괄호가 여는 괄호인데 다른 종류의 괄호에 의해 바로 닫혀버리면 0 반환
            if (i < s.size() - 1 && (s[i + 1] == '}' || s[i + 1] == ')'))
                return 0;
        }
        else if (s[i] == ']')
        {
            bracket1 -= 1;
        }
        else if (s[i] == '{')
        {
            bracket2 += 1;

            if (i < s.size() - 1 && (s[i + 1] == ']' || s[i + 1] == ')'))
                return 0;
        }
        else if (s[i] == '}')
        {
            bracket2 -= 1;
        }
        else if (s[i] == '(')
        {
            bracket3 += 1;

            if (i < s.size() - 1 && (s[i + 1] == ']' || s[i + 1] == '}'))
                return 0;
        }
        else if (s[i] == ')')
        {
            bracket3 -= 1;
        }

        // 각 괄호 스택 중 하나라도 음수가 되면 바로 0 반환
        if (bracket1 < 0 || bracket2 < 0 || bracket3 < 0)
            return 0;
    }
    // 마지막에 확인 했을 때 닫혀있지 않은 괄호가 있을 때는 0 반환 / 문제 없이 모든 문자열을 돌았다면 1 반환
    if (bracket1 == 0 && bracket2 == 0 && bracket3 == 0)
        return 1;
    else
        return 0;
}

int solution(string s) {
    string str = s;
    int count = 0;
    int sLen = s.size();

    for (int i = 0; i < sLen; i++)
    {
        count += CheckString(str);
        str = str.substr(1, sLen - 1) + str.substr(0, 1);  //  왼쪽으로 한 칸씩 회전   
        bracket1 = 0, bracket2 = 0, bracket3 = 0;
    }
    return count;
}