#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define MAX 105
#define INF 1e9

vector<vector<int> > graph;
vector<vector<int> > dist;
vector<vector<int> > path;

int n;

void printPath(int s, int t)
{
	int b[MAX];
	int m = 0;
	while (s != t)
	{
		b[m++] = t;
		t = path[s][t];
	}
	b[m++] = s;
	for (int i = m - 1; i >= 0; i--)
	{
		cout << b[i] << " ";
	}
}

void FloydWarshall(vector<vector<int> > &graph, vector<vector<int> > &dist)
{
	int i, j, k;
	for(i = 0;i<n;i++)
		for (j = 0; j < n; j++)
		{
			dist[i][j] = graph[i][j];
			if (graph[i][j] != INF && i != j)
			{
				path[i][j] = i;
			}
			else
			{
				path[i][j] = -1;
			}
		}
	for(k=0;k<n;k++)
		for (i = 0; i < n; i++)
		{
			for(j=0;j<n;j++)
				if (dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = path[k][j];
				}
		}
}
int main()
{
	freopen("INPUT.txt", "rt", stdin);
	int temp;
	cin >> n;
	graph = vector<vector<int> >(n, vector<int>(n));
	dist = vector<vector<int> >(n, vector<int>(n));
	path = vector<vector<int> >(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> temp;
			if (temp == 0 && i != j)
			{
				graph[i][j] = INF;
			}
			else
			{
				graph[i][j] = temp;
			}
		}
	}

	FloydWarshall(graph, dist);
	int s = 0;
	int t = 4;
	int result = dist[s][t];

	printPath(s, t);
	cout << result;
	return 0;
}