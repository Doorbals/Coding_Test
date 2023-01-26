#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <list>
#include <sstream>
#include <string>

#define _CRT_SECURE_NO_WARNINGS
#define MAX_NODE 100000

using namespace std;

int output[MAX_NODE];

struct Node {
	int data;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;
Node headNode;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

// 초기화 : 리스트를 전부 비움 -> head의 링크 필드를 nullptr로 하면 아무 것도 가리키지 않게 됨.
void init()
{
	head = &headNode;
	head->next = nullptr;
}

// 리스트의 맨 앞에 노드 삽입
void addNode2Head(int data)
{
	Node* node = getNode(data);

	node->next = head->next;
	head->next = node;
}

// 리스트의 맨 뒤에 노드 삽입
void addNode2Tail(int data)
{
	Node* node = getNode(data);
	Node* prev = head;

	while (prev->next != nullptr)
		prev = prev->next;

	prev->next = node;
}

// 리스트 지정 위치(num)에 노드 삽입
void addNode2Num(int data, int num)
{
	Node* node = getNode(data);
	Node* prev = head;

	for (int i = 0; i < num - 1; i++)
		prev = prev->next;

	node->next = prev->next;
	prev->next = node;
}

// 리스트 지정 위치(num)의 노드 삭제
void removeNodefromNum(int num)
{
	Node* prev = head;

	for (int i = 0; i < num - 1; i++)
		prev = prev->next;

	prev->next = prev->next->next;
}

// output[] 배열에 리스트 노드의 data 차례대로 넣음.
void getList()
{
	Node* prev = head;
	int count = 0;

	for (int i = 0; i < 10; i++)
	{
		prev = prev->next;
		output[count] = prev->data;
		count++;
	}
}

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

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	init();
	for (int i = 0; i < 10; i++)
	{
		int n;
		cin >> n;
		cin.ignore();

		string str1;
		getline(cin, str1);
		vector<string> result1 = split(str1, ' ');

		for (int j = result1.size() - 1; j >= 0; j--)
		{
			addNode2Head(stoi(result1[j]));
		}

		int m;
		cin >> m;
		cin.ignore();
		
		string str2;
		getline(cin, str2);
		vector<string> result2 = split(str2, ' ');

		char type = ' ';
		int nextI = 0, nextD = 0, nextA = 0;
		int index = 0;

		for (int j = 0; j < result2.size(); j++)
		{
			string code = result2[j];
			
			switch (code[0])
			{
				case 'I':
					type = 'I';
					nextI = 0;
					break;
				case 'D' :
					type = 'D';
					nextD = 0;
					break;
				case 'A' :
					type = 'A';
					nextA = 0;
					break;
				default :
					if(type == 'I')
					{
						if (nextI == 0)
						{
							index = stoi(code);
						}
						else if (nextI != 1)
						{
							addNode2Num(stoi(code), index + 1); // index일 수도
							index++;
						}
						nextI++;
					}
					else if (type == 'D')
					{
						if (nextD == 0)
						{
							index = stoi(code);
						}
						else if (nextD == 1)
						{
							for (int k = 0; k < stoi(code); k++)
							{
								removeNodefromNum(index + 1);
							}
						}
						nextD++;
					}
					else if (type == 'A')
					{
						if (nextA != 0)
						{
							addNode2Tail(stoi(code));
						}
						nextA++;
					}
					break;
			}
		}
		getList();
		cout << '#' << i + 1 << ' ';
		for (int j = 0; j < 10; j++)
		{
			cout << output[j] << ' ';
		}
		cout << "\n";
	}

	return 0;
}