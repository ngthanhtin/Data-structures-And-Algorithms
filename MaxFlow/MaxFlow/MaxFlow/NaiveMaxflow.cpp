// //#include <iostream>
// //#include <queue>
// //using namespace std;
// //
// //int const max = 100;
// //int const maxc = 1000;
// //int c[max][max], f[max][max], cf[max][max];
// //int path[max]; // trace path
// //			   // n is the number of vertices
// //			   //a is source vertice
// //			   //b is sink vertice
// //int n, a, b;
// //
// ////input the arguments
// //void enter()
// //{
// //	// m is the number of edges
// //	int m, u, v;
// //	for (int i = 0; i < max; i++)
// //	{
// //		for (int j = 0; j < max; j++)
// //		{
// //			c[i][j] = 0;
// //		}
// //	}
// //	cin >> n >> m >> a >> b;
// //	a--; // the first vertice begins at 0
// //	b--; // the sink vertice ends at n - 1
// //	for (int i = 0; i< m; i++)
// //	{
// //		cin >> u >> v; // two adjacent vertices
// //		cin >> c[u - 1][v - 1]; // weight
// //	}
// //}
// //// find increasing flow
// //void creategf()
// //{
// //	//build cf from c and f
// //	for (int u = 0; u < n; u++)
// //	{
// //		for (int v = 0; v <n; v++)
// //		{
// //			cf[u][v] = maxc;
// //		}
// //	}
// //	for (int u = 0; u < n; u++)
// //	{
// //		for (int v = 0; v <n; v++)
// //		{
// //			if (c[u][v] > 0) // if (u,v) is a bow in g
// //			{
// //				if (f[u][v] < c[u][v])
// //				{
// //					cf[u][v] = c[u][v] - f[u][v]; // normal bow
// //				}
// //				if (f[u][v] > 0)// inverse bow
// //				{
// //					cf[v][u] = -f[u][v];
// //				}
// //			}
// //		}
// //	}
// //}
// ////find a path from a to b using bfs
// //bool findpath()
// //{
// //	queue<int> q;
// //	bool isfound = false;
// //	bool visited[max] = { 0 };
// //	q.push(a);
// //	visited[a] = true;
// //	while (!q.empty())
// //	{
// //		int s = q.front();
// //		q.pop();
// //		for (int i = 0; i < n; i++)
// //		{
// //
// //			if (visited[i] == false && cf[s][i] != maxc)
// //			{
// //				visited[i] = true;
// //				q.push(i);
// //				path[i] = s;
// //				if (i == b) // have path from a to b
// //				{
// //					isfound = true;
// //					return isfound;
// //				}
// //			}
// //		}
// //	}
// //	return isfound;
// //}
// ////increase flow following the increasing flow path (have just found by bfs)
// //void incflow()
// //{
// //	int u, v, incvalue;
// //	// follow the path to find the smallest weight of bows on path
// //	incvalue = maxc;
// //	v = b;
// //	while (v != a)
// //	{
// //		u = path[v];
// //		if (abs(cf[u][v]) < incvalue)
// //		{
// //			incvalue = abs(cf[u][v]);
// //		}
// //		v = u;
// //	}
// //	// follow the path the second time to increase flow
// //	v = b;
// //	while (v != a)
// //	{
// //		u = path[v];
// //		if (cf[u][v] > 0)
// //		{
// //			f[u][v] = f[u][v] + incvalue; // (u,v ) is a normal bow
// //		}
// //		else
// //		{
// //			f[u][v] = f[u][v] - incvalue; // (u,v) is a inverse bow
// //		}
// //		v = u;
// //	}
// //}
// ////print the max-flow
// //void print()
// //{
// //	int m = 0;
// //	for (int u = 0; u < n; u++)
// //	{
// //		for (int v = 0; v < n; v++)
// //		{
// //			if (c[u][v] > 0)
// //			{
// //				cout << "f[" << u << "][" << v << "] = " << f[u][v] << endl;
// //				if (u == a)
// //				{
// //					m = m + f[a][v];
// //				}
// //			}
// //		}
// //	}
// //	cout << "max flow: " << m << endl;
// //}
int main()
{
	enter();
	for (int i = 0; i < max; i++)
	{
		for (int j = 0; j < max; j++)
		{
			f[i][j] = 0;
		}
	}

	do
	{
		creategf();
		if (findpath() == false)
			break;
		incflow();
	} while (true);
	print();
	return 0;
}