#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <list>
#include <sstream>
#include <string>

using namespace std;	
typedef tuple<int, char, int, int> ticii;

vector<ticii> nodes;

vector<string> split(string input, char dlim)
{
	vector<string> result;

	stringstream ss;
	string stringBuffer;
	ss.str(input);

	while (getline(ss, stringBuffer, dlim))
	{
		result.push_back(stringBuffer);
	}

	return result;
}

void inOrder(int currentNode)
{
	int left = get<2>(nodes[currentNode]);
	int right = get<3>(nodes[currentNode]);
	
	if (left != -1) inOrder(left);
	cout << get<1>(nodes[currentNode]);
	if (right != -1) inOrder(right);
}

int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	for (int t = 0; t < 10; t++)
	{
		string nStr;
		getline(cin, nStr);
		int n = stoi(nStr);

		for (int i = 0; i < n; i++)
		{
			string str;
			getline(cin, str);
			vector<string> splited = split(str, ' ');

			int nodeNum, left = 0, right = 0;
			char ch;
			if (splited.size() > 1)
			{
				nodeNum = stoi(splited[0]);
				ch = splited[1][0];
				if (splited.size() > 2)
				{
					left = stoi(splited[2]);
					if (splited.size() > 3)
						right = stoi(splited[3]);
				}
			}

			nodes.push_back(ticii(nodeNum, ch, left - 1, right - 1));
		}
		cout << '#' << t + 1 << ' ';
		inOrder(0);
		nodes.clear();
		cout << endl;
	}
}