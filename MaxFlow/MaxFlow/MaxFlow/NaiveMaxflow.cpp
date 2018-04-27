#include <iostream>
#include <queue>
using namespace std;

int const MAX = 100;
int const maxC = 1000;
int c[MAX][MAX], f[MAX][MAX], cf[MAX][MAX];
int path[MAX]; // trace path
			   // n is the number of vertices
			   //A is source vertice
			   //B is sink vertice
int n, A, B;

//input the arguments
void Enter()
{
	// m is the number of edges
	int m, u, v;
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			c[i][j] = 0;
		}
	}
	cin >> n >> m >> A >> B;
	A--; // the first vertice begins at 0
	B--; // the sink vertice ends at n - 1
	for (int i = 0; i< m; i++)
	{
		cin >> u >> v; // two adjacent vertices
		cin >> c[u - 1][v - 1]; // weight
	}
}
// find increasing flow
void CreateGf()
{
	//Build cf from c and f
	for (int u = 0; u < n; u++)
	{
		for (int v = 0; v <n; v++)
		{
			cf[u][v] = maxC;
		}
	}
	for (int u = 0; u < n; u++)
	{
		for (int v = 0; v <n; v++)
		{
			if (c[u][v] > 0) // if (u,v) is a bow in G
			{
				if (f[u][v] < c[u][v])
				{
					cf[u][v] = c[u][v] - f[u][v]; // normal bow
				}
				if (f[u][v] > 0)// inverse bow
				{
					cf[v][u] = -f[u][v];
				}
			}
		}
	}
}
//find a path from A to B using BFS
bool FindPath()
{
	queue<int> q;
	bool isFound = false;
	bool visited[MAX] = { 0 };
	q.push(A);
	visited[A] = true;
	while (!q.empty())
	{
		int s = q.front();
		q.pop();
		for (int i = 0; i < n; i++)
		{

			if (visited[i] == false && cf[s][i] != maxC)
			{
				visited[i] = true;
				q.push(i);
				path[i] = s;
				if (i == B) // have path from A to B
				{
					isFound = true;
					return isFound;
				}
			}
		}
	}
	return isFound;
}
//increase flow following the increasing flow path (have just found by BFS)
void IncFlow()
{
	int u, v, IncValue;
	// follow the path to find the smallest weight of bows on path
	IncValue = maxC;
	v = B;
	while (v != A)
	{
		u = path[v];
		if (abs(cf[u][v]) < IncValue)
		{
			IncValue = abs(cf[u][v]);
		}
		v = u;
	}
	// follow the path the second time to increase flow
	v = B;
	while (v != A)
	{
		u = path[v];
		if (cf[u][v] > 0)
		{
			f[u][v] = f[u][v] + IncValue; // (u,v ) is a normal bow
		}
		else
		{
			f[u][v] = f[u][v] - IncValue; // (u,v) is a inverse bow
		}
		v = u;
	}
}
//print the max-flow
void Print()
{
	int m = 0;
	for (int u = 0; u < n; u++)
	{
		for (int v = 0; v < n; v++)
		{
			if (c[u][v] > 0)
			{
				cout << "f[" << u << "][" << v << "] = " << f[u][v] << endl;
				if (u == A)
				{
					m = m + f[A][v];
				}
			}
		}
	}
	cout << "Max flow: " << m << endl;
}
int main()
{
	Enter();
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			f[i][j] = 0;
		}
	}

	do
	{
		CreateGf();
		if (FindPath() == false)
			break;
		IncFlow();
	} while (true);
	Print();
	return 0;
}