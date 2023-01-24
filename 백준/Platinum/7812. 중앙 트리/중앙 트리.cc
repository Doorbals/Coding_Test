#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;
typedef pair<int, int> pii;
typedef pair<long long, int> pli;
typedef tuple<int, long long, int> tili;

vector<vector<pii>> edges;   // 각 노드 v에 대해 (인접 노드, v와의 거리)를 저장하는 pair들의 벡터들을 저장하는 벡터
vector<vector<tili>> dp;     // 각 노드 v에 대해 (인접 노드, 인접 노드를 루트로 하는 서브트리에 있는 모든 노드들과 v 사이 거리의 총합, v 아래로 존재하는 노드 개수)
vector<vector<int>> dpIndex;
vector<bool> visited;

int n, a, b, w;
long long minDist;

pli DFS(long long distance, int currentNode)
{
    long long result = distance;
    int nodeCount = 0;
    visited[currentNode] = true;

    for (int i = 0; i < edges[currentNode].size(); i++)
    {
        int childNode = edges[currentNode][i].first;

        if (visited[childNode] == false)
        {
            visited[childNode] = true;
            if (dpIndex[currentNode][i] == -1)
            {
                pli tmp = DFS(distance + edges[currentNode][i].second, childNode);
                result += tmp.first;
                nodeCount += tmp.second + 1;
                dp[currentNode].push_back(tili(childNode, tmp.first - ((long long)tmp.second + 1) * distance, tmp.second + 1));
                dpIndex[currentNode][i] = dp[currentNode].size() - 1;
            }
            else
            {
                tili dpData = dp[currentNode][dpIndex[currentNode][i]];
                nodeCount += get<2>(dpData);
                result += get<1>(dpData) + (long long)get<2>(dpData) * distance;
            }
            visited[childNode] = false;
        }
    }
    return pli(result, nodeCount);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();

    while (true)
    {
        cin >> n;
        if (n == 0)
            return 0;

        edges.clear();
        edges.resize(n);
        dp.clear();
        dp.resize(n);
        visited.clear();
        visited.assign(n, false);
        dpIndex.clear();
        dpIndex.resize(n);

        for (int i = 0; i < n - 1; i++)
        {
            cin >> a >> b >> w;

            edges[a].push_back(pii(b, w));
            edges[b].push_back(pii(a, w));
            dpIndex[a].push_back(-1);
            dpIndex[b].push_back(-1);
        }

        minDist = DFS(0, 0).first;
        for (int i = 0; i < n; i++)
        {
            long long dfs = DFS(0, i).first;

            if (dfs < minDist)
                minDist = dfs;

            visited.assign(n, false);
        }
        cout << minDist << '\n';
    }
}
