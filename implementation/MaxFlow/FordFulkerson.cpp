#include <iostream>
#include <queue>
using namespace std;

int const MAX = 100;
int const maxC = 10000;
int c[MAX][MAX], f[MAX][MAX];
int path[MAX]; // trace path
int Delta[MAX];
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
	for (int i = 0; i< m; i++)
	{
		cin >> u >> v; // two adjacent vertices
		cin >> c[u][v]; // weight
	}
}
//find a path from A to B using BFS
bool FindPath()
{
	queue<int> q;
	bool isFound = false;
	q.push(A);
	Delta[A] = maxC;
	path[A] = n + 1;
	for (int i = 1; i <= n; i++)
	{
		path[i] = 0;
	}
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int v = 1; v <= n; v++)
		{
			if (path[v] == 0) // i'th vertice is not visited
			{
				if (f[u][v] < c[u][v]) // if (s,i) is normal bow
				{
					path[v] = u;//trace
					Delta[v] = min(Delta[u], c[u][v] - f[u][v]);
				}
				else
				{
					if (f[v][u] > 0) // if (s,i) is reverse bow
					{
						path[v] = -u;
						Delta[v] = min(Delta[u], f[v][u]);
					}
				}
				if (path[v] != 0) // path[i] != 0 means 's' can visit 'i'
				{
					if (v == B)
					{
						cout << Delta[B] << endl;
						isFound = true;
						return isFound;
					}
					q.push(v);
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
	IncValue = Delta[B];
	v = B;
	while (v != A)
	{
		u = path[v];
		if (u > 0) // means normal bow
		{
			f[u][v] = f[u][v] + IncValue;
		}
		else// means inverse bow
		{
			u = -u;
			f[v][u] = f[v][u] - IncValue;
		}
		v = u;
	}
}
//print the max-flow
void Print()
{
	int m = 0;
	for (int u = 1; u <= n; u++)
	{
		for (int v = 1; v <= n; v++)
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
		if (FindPath() == false)
			break;
		IncFlow();
	} while (true);
	Print();
	return 0;
}