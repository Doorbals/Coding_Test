#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int n, m, k, start;			// 노드의 개수, 간선의 개수, 거리 정보, 시작 노드 번호
vector<vector<pii>> graph;	// 그래프 데이터 저장 (노드 개수는 최대 100000개)
int d[300001];				// 최단 거리 테이블
const long long INF = 1e9;	// 무한을 의미하는 값

void dijkstra(int start)
{
	priority_queue<pii, vector<pii>, greater<pii>> pq;	// priority_queue는 최대힙으로 구현되어 있으므로, 최소힙으로 작동하기 위해 greater 추가
	pq.push(pii(0, start));
	d[start] = 0;

	while (!pq.empty())
	{
		// 가장 최단거리가 짧은 노드에 대한 정보 꺼내기
		int dist = pq.top().first;	// 현재 노드까지의 비용
		int cur = pq.top().second;	// 현재 노드 번호
		pq.pop();
		// 현재 노드가 이미 처리된 적이 있는 노드라면 무시
		if (d[cur] < dist) continue;
		// 현재 노드와 연결된 다른 인접 노드들을 확인
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int cost = dist + graph[cur][i].second;
			// 현재 노드를 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
			if (cost < d[graph[cur][i].first])
			{
				d[graph[cur][i].first] = cost;
				pq.push(pii(cost, graph[cur][i].first));
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m >> k >> start;
	graph.resize(n + 1);
	// 간선 정보 입력 받기
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(pii(b, 1));	// a 노드에서 b 노드로 가는 비용이 c라는 의미
	}

	// 최단거리 테이블을 모두 무한으로 초기화
	fill(d, d + 300001, INF);
	
	// 다익스트라 알고리즘 수행
	dijkstra(start);

	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (d[i] == k)
			cout << i << endl;
		else
			count++;
	}

	if (count == n)
		cout << -1;
}