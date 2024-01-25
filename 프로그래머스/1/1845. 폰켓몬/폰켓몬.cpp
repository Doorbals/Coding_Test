#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    int max = nums.size() / 2;
    set<int> s;
    
    for(int i = 0; i < nums.size(); i++)
    {
        s.insert(nums[i]);    
    }
    
    int size = s.size();
    
    return max < size ? max : size;
}