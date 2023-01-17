#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

vector<vector<pii>> cities;	// 각 도시들에 대한 pair(인접한 도시, 도시 간의 거리)들의 벡터를 저장하는 벡터
//bool visited[50001];		// 각 도시들의 방문 여부 체크
vector<int> dist;			// 임의 정점에서부터 다른 도시들까지의 거리
int dist_v1[50001];			// vertex1에서부터 다른 도시들까지의 거리
int dist_v2[50001];			// vertex2에서부터 다른 도시들까지의 거리
int maxDistance;			// 임의 정점에서 가장 먼 도시에 갔을 때의 거리
int farCity;				// 임의의 정점에서 가장 먼 도시

void DFS(int distance, int currentCity)
{
	dist[currentCity] = distance;	// 도시가 n개일 때 경로가 n - 1개 밖에 없기 때문에 한 도시로 가는 경로는 한 가지 밖에 없음.
	if (dist[currentCity] > maxDistance)
	{
		maxDistance = distance;
		farCity = currentCity;
	}

	for (int i = 0; i < cities[currentCity].size(); i++)
	{
		int nearCity = cities[currentCity][i].first;
		
		if (dist[nearCity] == 50000)
		{
			//visited[nearCity] = true; 
			DFS(distance + cities[currentCity][i].second, nearCity);
			//visited[nearCity] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int n;
	cin >> n;

	cities.resize(n);
	dist.assign(n, 50000);

	for (int i = 0; i < n - 1; i++)
	{
		int from, to, length;
		cin >> from >> to >> length;
		
		// 도로는 양쪽 연결되어있으므로 from 도시의 인접 도시에 to를 넣고, to 도시의 인접 도시에 from을 넣는다.
		cities[from - 1].push_back(pii(to - 1, length));
		cities[to - 1].push_back(pii(from - 1, length));
	}

	// 임의의 정점(도시) 하나에서 시작하여 DFS 실행해 해당 정점에서 가장 먼 정점 찾아 vertex1에 저장
	//visited[0] = true;
	DFS(0, 0);
	//visited[0] = false;
	int vertex1 = farCity;

	dist.assign(n, 50000);
	maxDistance = 0;
	// vertex1에서 시작하여 DFS 실행해 가장 먼 정점 찾아 vertex2에 저장 및 각 도시까지의 거리 구해 dist_v1에 저장
	//visited[vertex1] = true;
	DFS(0, vertex1);
	//visited[vertex1] = false;
	int vertex2 = farCity;

	for(int i = 0; i < dist.size(); i++)
		dist_v1[i] = dist[i];

	dist.assign(n, 50000);
	maxDistance = 0;
	// vertex2에서 시작하여 DFS 실행해 각 도시까지의 거리 구해 dist_v2에 저장
	//visited[vertex2] = true;
	DFS(0, vertex2);
	//visited[vertex2] = false;
	
	for (int i = 0; i < n; i++)
		cout << (dist_v1[i] > dist[i] ? dist_v1[i] : dist[i]) << endl;
}