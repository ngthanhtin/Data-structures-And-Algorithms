#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
#define MAX 100
const int INF = 1e9;
vector<vector<pair<int, int> > > graph;
vector<int> dist(MAX, INF);
int path[MAX];

void Dijkstra(int source, vector<vector<pair<int, int> > > &v, vector<int> &distance)
{
	//tạo một hàng đợi ưu tiên phần tử có độ ưu tiên cao nhất là phần tử có giá trị nhỏ nhất(greater)
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	//first: chi phí, source đỉnh.
	pq.push(pair<int, int>(0, source));
	//gán đỉnh bắt đầu chi phí là 0
	distance[source] = 0;

	while (!pq.empty())
	{
		pair<int, int> top = pq.top();
		pq.pop();
		int node = top.second;
		int d = top.first;
		for (int i = 0; i < v[node].size(); ++i)
		{
			pair<int, int> neighbor = v[node][i];
			if (d + neighbor.second < distance[neighbor.first])
			{
				distance[neighbor.first] = d + neighbor.second;
				pq.push(pair<int, int>(distance[neighbor.first], neighbor.first));
				path[neighbor.first] = node;
			}
		}
	}
}
int main()
{
	//freopen("INPUT.txt", "rt", stdin);
	int n, s, t;
	dist = vector<int>(MAX, INF);
	cin >> n >> s >> t;
	graph = vector<vector<pair<int, int> > >(MAX + 5, vector<pair<int, int> >());
	int d = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> d;
			if (d > 0)
				graph[i].push_back(pair<int, int>(j, d));
		}
	}
	Dijkstra(s, graph, dist);
	int ans = dist[t];
	cout << ans;
	return 0;
}