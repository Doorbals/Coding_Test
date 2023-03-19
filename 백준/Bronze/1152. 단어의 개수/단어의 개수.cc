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
	
	vector<string> result;
	stringstream ss;
	string stringBuffer;
	ss.str(str);
	while (getline(ss, stringBuffer, ' '))
	{
		if(stringBuffer != " ")
			result.push_back(stringBuffer);
	}

	cout << result.size();
}
