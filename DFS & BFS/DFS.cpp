#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#define MAX 100
int V;
bool visited[MAX];
int path[MAX];
vector<int> graph[MAX];
// print path from u to v
void printPathRecursion(int u,int v)
{
    if(u == v)
        cout<<v<<" ";
    else
        if(path[v] == -1)
            cout<<"No path"<<endl;
        else
        {
            printPathRecursion(u, path[v]);
            cout<<v<<" ";
        }
}
//main algorithm
void DFS(int src)
{
    memset(visited, 0, sizeof(visited));
    memset(path, -1, sizeof(path));

    stack<int> s;
    visited[src] = true;
    s.push(src);
    
    while(!s.empty())
    {
        src = s.top();
        s.pop();
        for(int i = 0; i < graph[src].size(); i++)
        {
            if(!visited[i])
            {
                visited[i] = true; // label to visited
                s.push(i);
                path[i] = src;
            }
        }
    }
}
int main()
{
    freopen("in.txt", "rt", stdin);
    int E, u, v;
    cin>>V>>E;
    for(int i = 0;i<E;i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int s = 0;
    int d = 5;
    DFS(s);
    printPathRecursion(s,d,path);
    return 0;
}