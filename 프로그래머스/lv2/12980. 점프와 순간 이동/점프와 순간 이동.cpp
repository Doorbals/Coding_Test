#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int solution(int n)
{
    int count = 0;
    while (n != 0)
    {
        if (n % 2 == 0)
            n = n / 2;
        else
        {
            n = n - 1;
            count++;
        }
    }
    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();

    int n;
    cin >> n;

    cout << solution(n);
}
