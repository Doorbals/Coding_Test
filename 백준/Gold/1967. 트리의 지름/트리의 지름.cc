#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;
typedef pair<int, int> pii;
vector<vector<pii>> edges;
vector<long long> dist;
int maxDist = 0;
int farNode;
int dia_node;

void DFS(long long distance, int currentNode)
{
    dist[currentNode] = distance;
    if (dist[currentNode] > maxDist)
    {
        maxDist = dist[currentNode];
        farNode = currentNode;
    }
        
    for (int i = 0; i < edges[currentNode].size(); i++)
    {
        int nextNode = edges[currentNode][i].first;

        if (dist[nextNode] == -1)
        {
            DFS(distance + edges[currentNode][i].second, nextNode);
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    
    int n;
    cin >> n;

    edges.resize(n);
    dist.assign(n, -1);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;

        edges[a - 1].push_back(pii(b - 1, w));
        edges[b - 1].push_back(pii(a - 1, w));
    }

    DFS(0, 0);
    dia_node = farNode;

    maxDist = 0;
    dist.assign(n, -1);
    DFS(0, dia_node);
    cout << maxDist;
}