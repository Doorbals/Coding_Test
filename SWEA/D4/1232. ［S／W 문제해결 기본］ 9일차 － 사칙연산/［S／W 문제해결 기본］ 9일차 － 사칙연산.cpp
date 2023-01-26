#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <list>
#include <sstream>
#include <string>

using namespace std;	
typedef tuple<int, string, int, int> tisii;

vector<tisii> nodes;

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

long long inOrder(int currentNode)
{
	int left = get<2>(nodes[currentNode]);
	int right = get<3>(nodes[currentNode]);
	long long leftResult = 0, rightResult = 0;
	char currentOp = get<1>(nodes[currentNode])[0];

	// 연산자 왼쪽 서브트리의 계산 결과 구하기
	if (left != -1)
		leftResult = inOrder(left);
	else
		return stoll(get<1>(nodes[currentNode]));	// 사칙연산이 가능하기 위해서는 말단 노드는 항상 숫자이므로 바로 반환
	
	// 연산자 오른쪽 서브트리의 계산 결과 구하기
	if (right != -1)
		rightResult = inOrder(right);
	else
		return stoll(get<1>(nodes[currentNode]));

	switch(currentOp)								// 사칙연산이 가능하기 위해서는 각 서브 트리의 루트 노드는 항상 연산자. 따라서 루트의 양쪽 자식을 연산자로 계산 
	{
		case '+':
			return leftResult + rightResult;
			break;
		case '-':
			return leftResult - rightResult;
			break;
		case '*':
			return leftResult * rightResult;
			break;
		case '/':
			return leftResult / rightResult;
			break;
	}
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
			string ch;
			if (splited.size() > 1)
			{
				nodeNum = stoi(splited[0]);
				ch = splited[1];
				if (splited.size() > 2)
				{
					left = stoi(splited[2]);
					if (splited.size() > 3)
						right = stoi(splited[3]);
				}
			}
			nodes.push_back(tisii(nodeNum, ch, left - 1, right - 1));
		}
		cout << '#' << t + 1 << ' ';
		cout << inOrder(0) << endl;

		nodes.clear();
	}
}