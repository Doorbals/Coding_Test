#include <iostream>
#include <algorithm>
#include <tuple>
#include <string>
#include <queue>

using namespace std;
typedef pair<int, int> pii; // 사람 수, 인덱스

// 사람 수의 내림차순으로 정렬하는 비교연산자 구현
struct Compare
{
	bool operator()(pii a, pii b)
	{
		return a.first < b.first;
	}
};


int main(int argc, char** argv)
{
	priority_queue<pii, vector<pii>, Compare> pq;	// 우선순위 큐 선언 (사람 수의 내림차순으로 우선순위 큼) 
	vector<int> pVec;	// 기호 별 사람 수 저장 
	int n = 0, dasom = 0, count = 0;
	cin >> n;
	cin >> dasom;
	pVec.push_back(dasom);

	if (n == 1)
	{
		cout << 0;
		return 0;
	}
		
	for (int i = 1; i < n; i++)
	{
		int pNum;	// 사람 수
		cin >> pNum;
		pVec.push_back(pNum);
		pq.push(pii(pNum, i));
	}

	while (true)
	{
		for (int i = 1; i < pVec.size(); i++)
		{
			if (pVec[0] <= pVec[i])
				break;
			
			if (i == pVec.size() - 1)
			{
				cout << count;
				return 0;
			}		
		}

		int topNum = pq.top().first;
		int index = pq.top().second;
		pq.pop();
		pq.push(pii(topNum - 1, index));
		pVec[0] += 1;
		pVec[index] = topNum - 1;
		count++;
	}
}