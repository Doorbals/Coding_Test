#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, long long left, long long right)
{
    vector<int> result;
    for (long long i = left; i <= right; i++)
    {
        long long y = i / n;
        long long x = i % n;
        result.push_back(max(y, x) + 1);
    }
    return result;
}