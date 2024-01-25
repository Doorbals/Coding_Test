#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums)
{
    int max = nums.size() / 2;
    unordered_set<int> s(nums.begin(), nums.end());

    int size = s.size();
    return max < size ? max : size;
}