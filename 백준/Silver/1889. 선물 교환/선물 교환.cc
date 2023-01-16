#include <stdio.h>
#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int n = 0;
	cin >> n;

	vector<tuple<int, bool, int, int>> students(n);	// 진입차수(선물 받은 수), 참여 여부, 진출노드 1(해당 학생이 선물 준 학생 1), 진출노드 2(학생 2)

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;

		// i번째 학생이 선물을 준 학생들의 진입 차수 + 1
		get<0>(students[a - 1]) += 1;
		get<0>(students[b - 1]) += 1;

		// 참여 여부 갱신
		get<1>(students[i]) = true;

		// i번째 학생이 선물 준 학생 1, 2 갱신
		get<2>(students[i]) = a;
		get<3>(students[i]) = b;
	}

	bool check = false;
	int check_erase = 0;

	while(!check)
	{
		int count = 0;
		for (int i = 0; i < students.size(); i++)
		{
			if (get<0>(students[i]) < 2 && get<1>(students[i]))
			{
				int a = get<2>(students[i]);
				int b = get<3>(students[i]);

				get<0>(students[a - 1]) -= 1;
				get<0>(students[b - 1]) -= 1;

				get<1>(students[i]) = false;
			}
			else
			{
				if (!get<1>(students[i]) || get<0>(students[i]) == 2)
					count++;
			}
		}
		if (count == n)
			check = true;
	}

	vector<int> result;

	for (int i = 0; i < n; i++)
	{
		if (get<1>(students[i]))
			result.push_back(i + 1);
	}

	cout << result.size();

	if (result.size() > 0)
	{
		cout << '\n';
		for (int i = 0; i < result.size(); i++)
			cout << result[i] << ' ';
	}
	
}