#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) 
{
    vector<int> set_int(n, 0);
    vector<char> set_char(n, ' ');

    vector<vector<int>> arr1_map(n, set_int);
    vector<vector<int>> arr2_map(n, set_int);
    vector<vector<char>> result(n, set_char);

    int maxBin = (int)pow(2, n - 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == 0)
            {
                arr1_map[i][j] = arr1[i] / maxBin;
                arr1[i] -= maxBin * (arr1[i] / maxBin);
            }
            else
            {
                arr1_map[i][j] = arr1[i] / (maxBin / (int)pow(2, j));
                arr1[i] -= (maxBin / (int)pow(2, j)) * (arr1[i] / (maxBin / (int)pow(2, j)));
            }
        }

        for (int k = 0; k < n; k++)
        {
            if (k == 0)
            {
                arr2_map[i][k] = arr2[i] / maxBin;
                arr2[i] -= maxBin * (arr2[i] / maxBin);
            }
            else
            {
                arr2_map[i][k] = arr2[i] / (maxBin / (int)pow(2, k));
                arr2[i] -= (maxBin / (int)pow(2, k)) * (arr2[i] / (maxBin / (int)pow(2, k)));
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr1_map[i][j] == 1 || arr2_map[i][j] == 1)
                result[i][j] = '#';
        }
    }

    vector<string> answer;
    for (int i = 0; i < n; i++)
    {
        string str;
        for (int j = 0; j < n; j++)
        {
            str += result[i][j];
        }
        answer.push_back(str);
    }

    return answer;
}