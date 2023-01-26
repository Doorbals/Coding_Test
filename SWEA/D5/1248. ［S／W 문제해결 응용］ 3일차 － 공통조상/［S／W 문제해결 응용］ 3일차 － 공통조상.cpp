#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <list>
#include <sstream>
#include <string>

using namespace std;	
typedef pair<int, int> pii;
typedef tuple<int, bool, bool> tibb;

vector<vector<int>> nodes; 
vector<int> nodeCount;
int parentNodeNum = -1;

tibb dfs(int currentNode, int num1, int num2)
{
	int count = 0;
	bool num1Check = false, num2Check = false;
	for (int i = 0; i < nodes[currentNode].size(); i++)
	{
		tibb dfsResult = dfs(nodes[currentNode][i], num1, num2);
		count += get<0>(dfsResult);
		if (get<1>(dfsResult)) num1Check = get<1>(dfsResult);
		if (get<2>(dfsResult)) num2Check = get<2>(dfsResult);
	}
	if (currentNode == num1 - 1) num1Check = true;
	if (currentNode == num2 - 1) num2Check = true;

	if (num1Check && num2Check && parentNodeNum == -1)
		parentNodeNum = currentNode;

	nodeCount[currentNode] = count + 1;
	return tibb(count + 1, num1Check, num2Check);
}


int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int v, e, num1, num2;
		cin >> v >> e >> num1 >> num2;

		nodes.resize(v);
		nodeCount.resize(v);
		for (int j = 0; j < e; j++)
		{
			int p, c;
			cin >> p >> c;
			nodes[p - 1].push_back(c - 1);
		}
		dfs(0, num1, num2);
		cout << '#' << i + 1 << ' ' << parentNodeNum + 1 << ' ' << nodeCount[parentNodeNum] << endl;

		nodes.clear();
		nodeCount.clear();
		parentNodeNum = -1;
	}
	return 0;
}