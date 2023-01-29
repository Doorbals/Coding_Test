#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>

using namespace std;	


int main(void) 
{
	long long a, b;
	cin >> a >> b;
	if (a - b > 0)
		cout << a - b;
	else
		cout << (a - b) * -1;
}