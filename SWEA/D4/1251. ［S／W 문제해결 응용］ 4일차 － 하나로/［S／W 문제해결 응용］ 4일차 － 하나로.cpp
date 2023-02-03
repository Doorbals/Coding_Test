#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>

using namespace std;
typedef pair<long long, long long> pll;

vector<pll> positions;
vector<vector<pll>> edges;
bool mst[1001];
long long answer = 0;

void prim(int n)
{
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	int i = 1, count = 1;

	while (count < n)
	{
		mst[i] = true;

		for (int j = 0; j < edges[i].size(); j++)
		{
			int curNode = edges[i][j].second;
			if (!mst[curNode])
			{
				pq.push(edges[i][j]);
			}
		}

		for (int k = 0; k < pq.size(); k++)
		{
			pll curEdge = pq.top();
			pq.pop();
			if (!mst[curEdge.second])
			{
				answer += curEdge.first;
				count++;
				i = curEdge.second;
				break;
			}
		}
	}
}

long long calcDist(pll a, pll b)
{
	return (pow((a.first - b.first), 2) + pow((a.second - b.second), 2));
}

void init()
{
	positions.clear();
	edges.clear();
	for (int i = 0; i < 1001; i++)
		mst[i] = false;
	answer = 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		long long n;
		double e;
		cin >> n;

		vector<long long> px, py;
		for (int j = 0; j < n; j++)
		{
			long long x;
			cin >> x;
			px.push_back(x);
		}

		for (int j = 0; j < n; j++)
		{
			long long y;
			cin >> y;
			py.push_back(y);
		}
		cin >> e;

		for (int j = 0; j < n; j++)
			positions.push_back(pll(px[j], py[j]));

		edges.resize(n * (n - 1) + 1);
		for (int j = 0; j < positions.size(); j++)
		{
			for (int k = 0; k < positions.size(); k++)
			{
				if (j != k)
				{
					edges[j].push_back(pll(calcDist(positions[j], positions[k]), k));
					edges[k].push_back(pll(calcDist(positions[k], positions[j]), j));
				}
			}
		}
		prim(n);
		cout << fixed;
		cout.precision(0);
		cout << '#' << i + 1 << ' ' << round(answer * e) << endl;
		init();
	}
}