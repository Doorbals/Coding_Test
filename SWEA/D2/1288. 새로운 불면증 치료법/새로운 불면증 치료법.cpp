#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void solution(int n)
{
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		int mul = 1;
		bool arr[10];
		for (int j = 0; j < 10; j++)
			arr[j] = false;
		bool complete = false;

		while (true)
		{
			string strNum = to_string(num * mul);

			for (int j = 0; j < strNum.size(); j++)
			{
				arr[strNum[j] ^ 48] = true;
			}

			for (int k = 0; k < 10; k++)
			{
				if (!arr[k])
					break;

				if (k == 9)
				{
					cout << '#' << i + 1 << ' ' << num * mul << endl;
					complete = true;
				}
			}
			if (complete)
				break;
			mul++;
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int n;
	cin >> n;

	solution(n);
} 