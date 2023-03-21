#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	long long a, b, c;
    long long result = 0;
    cin >> a >> b >> c;
    result += a;
    result += b;
    result += c;
    cout << result;
}
