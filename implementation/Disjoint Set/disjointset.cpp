#include <iostream>
using namespace std;
#define MAX 101
int parent[MAX;
int findSet(int u)
{
    while(u != parent[u])
        u = parent[u];
    return u;
}
void unionSet(int u, int v)
{
    int up = findSet(u);
    int vp = findSet(v);
    parent[vp] = up;
}
int main()
{
    return 0;
}