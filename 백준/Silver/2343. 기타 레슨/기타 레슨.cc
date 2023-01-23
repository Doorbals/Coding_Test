#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> arr;
int input;
int sum = 0;        // 전체 강의 길이
int minBlu = 0;     // 전체 강의 길이 / 블루레이 개수 (최선의 경우의 최소 블루레이 크기)
int maxLen = 0;     // 가장 긴 강의

int lowerBound(int n, int m)
{
    int start = minBlu, end = sum, mid;   // start : 최선의 경우 최소 블루레이 크기

    while (end > start)
    {
        mid = (start + end) / 2;
        int tmpSum = 0;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            tmpSum += arr[i];
            if (tmpSum > mid)
            {
                count++;
                i -= 1;
                tmpSum = 0;
                if (count > m)
                    break;
            }
        }
        if (count <= m - 1)
            end = mid;
        else
            start = mid + 1;
    }
    return end;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();

    int n;
    float m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> input;
        arr.push_back(input);
        sum += input;
        if (input > maxLen)
            maxLen = input;
    }

    minBlu = round(sum / m);
    
    cout << lowerBound(n, m);
}
