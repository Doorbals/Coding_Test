#include <string>
#include <vector>
#include <set>

using namespace std;

bool solution(vector<string> phone_book) {
    set<string> s(phone_book.begin(), phone_book.end());
    
    for(int i = 0; i < phone_book.size(); i++)
    {
        for(int j = 0; j < phone_book[i].length(); j++)
        {
            string sstr = phone_book[i].substr(0, j);
            if(s.find(sstr) != s.end())
            {
                return false;
            }
        }
    }
    
    return true;
}