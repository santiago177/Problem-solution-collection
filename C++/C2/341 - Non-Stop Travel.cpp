#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
#include <utility>

using namespace std;

int main()
{
    //freopen("341 - Non-Stop Travel.in", "r", stdin);
    int n, c = 0;
    while(scanf("%d", &n) && n != 0)
    {
        int m, i, d, s, e;
        vector<pair<int, int> > graph[11];
        bool visited[11];
        int dist[11];
        int path[11];
        for(int z = 1; z <= n; z++)
        {
            scanf("%d", &m);
            visited[z] = false;
            path[z] = -1;
            dist[z] = 1<<30;
            for(int b = 0; b < m; b++)
            {
                scanf("%d %d", &i, &d);
                graph[z].push_back(make_pair(i, d));
            }
        }
        scanf("%d %d", &s, &e);
        int current = s;
        dist[s] = 0;
        path[s] = 0;
        priority_queue<pair<int, int> > min;
        while(1)
        {
            visited[current] = true;
            for(int a = 0; a < graph[current].size(); a++)
            {
                pair<int, int> t = graph[current][a];
                d = dist[current]+t.second;
                if(!visited[t.first] && d < dist[t.first])
                {
                    dist[t.first] = d;
                    path[t.first] = current;
                    min.push(make_pair(-d, t.first));
                }
            }
            if(min.empty())
                break;
            current = min.top().second;
            min.pop();
        }
        stack<int> paths;
        paths.push(e);
        current = e;
        while(current != s)
        {
            paths.push(path[current]);
            current = path[current];
        }
        cout<<"Case "<<++c<<": Path =";
        while(!paths.empty())
        {
            cout<<" "<<paths.top();
            paths.pop();
        }
        cout<<"; "<<dist[e]<<" second delay"<<endl;
    }
    return 0;
}










