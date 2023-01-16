#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int depth = 0;
string stack = "";
int count = 0;

void DFS(int, int, vector<int>, string, int);

int solution(vector<int> numbers, int target) 
{
	numbers.insert(numbers.begin(), 0);
    DFS(depth, target, numbers, stack, 0);
	return count;
}

void DFS(int depth, int target, vector<int> numbers, string stack, int sum)
{
	string answer = stack;
	int currentSum = sum;
	
	if(depth < numbers.size() - 1)
	{
		currentSum += numbers[depth + 1];
		answer += "+" + to_string(numbers[depth + 1]);
		DFS(depth + 1, target, numbers, answer, currentSum);
		
		currentSum -= numbers[depth + 1] * 2;
		answer = stack;
		answer += to_string(numbers[depth + 1] * -1);
		DFS(depth + 1, target, numbers, answer, currentSum);
	}
	else if(currentSum == target)
	{
		//cout << answer + " = " + to_string(currentSum) << endl;
		count++;
	}
}