#include <iostream>
#include <vector>
using namespace std;
#define MAX 105

const int INF = 1e9;

struct triad
{
	int source;
	int target;
	int weight;
};

vector<int> dist(MAX, INF);
vector<triad> graph;

int n, m;
int path[MAX];

bool BellmanFord(int source, vector<triad> &graph, vector<int> &dist)
{
	int u, v, w;
	dist[source] = 0;

	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = 0; j < m; j++)
		{
			u = graph[j].source;
			v = graph[j].target;
			w = graph[j].weight;

			if (dist[u] != INF && (dist[u] + w < dist[v]))
			{
				dist[v] = dist[u] + w;
				path[v] = u;
			}
		}
	}
	//để đảm bảo không tồn tại chu trình âm thì bellman-ford mới tìm được đường đi
	for (int i = 0; i < m; i++)
	{
		u = graph[i].source;
		v = graph[i].target;
		w = graph[i].weight;

		if (dist[u] != INF && (dist[u] + w < dist[v]))
		{
			return false;
		}
	}
	return true;
}

int main()
{
	freopen("INPUT.txt", "rt", stdin);
	int s, t, u, v, w;
	cin >> n >> m;
	dist = vector<int>(n, INF);

	for (int i = 0; i < m; i++)
	{
		triad temp;
		cin >> u >> v >> w;
		temp.source = u;
		temp.target = v;
		temp.weight = w;
		graph.push_back(temp);
	}
	s = 0;
	t = 4;
	bool res = BellmanFord(s, graph, dist);
	if (res == false)
	{
		cout << "Graph contains negative weight cycle\n";
	}
	else
	{
		cout << dist[t] << endl;
	}
	return 0;
}