#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int solution(vector<int> distance, vector<int> price)
{
	long long totalPrice = 0;
	int disIdx = 0, priceA = 0, priceB = 1;

	for (int i = 0; i < distance.size(); i++)
	{
		totalPrice += (price[priceA] * distance[disIdx]);
		if (price[priceA] <= price[priceB])
			priceB++;
		else
		{
			priceA = priceB;
			priceB = priceA + 1;
		}
		disIdx++;
	}
	return totalPrice;
}

int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int n;
	cin >> n;

	vector<int> dis;
	vector<int> price;

	for (int i = 0; i < n - 1; i++)
	{
		int d;
		cin >> d;
		dis.push_back(d);
	}

	for (int i = 0; i < n; i++)
	{
		int p;
		cin >> p;
		price.push_back(p);
	}

	cout << solution(dis, price);
}