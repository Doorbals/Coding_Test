#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string str;
	getline(cin, str);
	if (str[0] == ' ')
		str.erase(str.begin());
	if (str[str.size() - 1] == ' ')
		str.erase(str.end() - 1);

	int count = 0;
	bool existAlpha = false;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
			count++;
		else
			existAlpha = true;
	}
	if (existAlpha)
		cout << count + 1;
	else
		cout << 0;
}
