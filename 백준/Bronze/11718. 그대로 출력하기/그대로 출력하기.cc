#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int count = 0;
	while (count <= 100)
	{
		string str;
		getline(cin, str);
		cout << str << '\n';
		count++;
	}
}
