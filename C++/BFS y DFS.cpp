#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

stack<int> s;
queue<int> q;
vector<vector <int> > graph;
bool visited[10000];
void theDFS();
void theBFS();
void DFS(int pos)
{
        s.push(pos);
        theDFS();
        cout<<endl;
}
void BFS(int pos)
{
        q.push(pos);
        visited[pos] = true;
        while(!q.empty())
        {
            int p = q.front();
            cout<<p<<" ";
            q.pop();
            for(int a = 0; a < graph[p].size(); a++)
            {
                if(!visited[graph[p][a]])
                {
                    q.push(graph[p][a]);
                    visited[graph[p][a]] = true;
                }
            }
        }
        cout<<endl;
}
void theDFS()
{
    if(!s.empty())
    {
        int p = s.top();
        cout<<p<<" ";
        visited[p] = true;
        for(int a = 0; a < graph[p].size(); a++)
        {
            if(!visited[graph[p][a]])
            {
                s.push(graph[p][a]);
                theDFS();
            }
        }
        s.pop();
    }
}

int main()
{
    freopen("g3.in", "r", stdin);
    freopen("dfs.out", "w", stdout);
    int n;

    cin>>n;
    vector<vector <int> > g1(n);
    int b, c;
    for(int a = 0; a < n; a++)
        visited[a] = false;
    while(cin >> b >> c && b != -1)
    {
        g1[b].push_back(c);
        g1[c].push_back(b);

    }
    graph = g1;
    cout<<"DFS"<<endl;
    DFS(1);
    for(int a = 0; a < n; a++)
        visited[a] = false;
    cout<<endl;
    cout<<"BFS"<<endl;
    BFS(1);
    return 0;
}
