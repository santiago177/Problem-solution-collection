//#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int main()
{
//    freopen("336 - A Node Too Far.in", "r", stdin);
//    freopen("336 - A Node Too Far.out", "w", stdout);
    int n;
    int cas = 0;
    while(scanf("%d", &n) && n != 0)
    {
        vector<int> graph[100000];
        bool used[100000] = {false};
        int cont = 0;
        int start, ttl;
        for(int a = 0; a < n; a++)
        {
            int b, c;
            scanf("%d %d", &b, &c);
            graph[b].push_back(c);
            graph[c].push_back(b);
            if(!used[b])
            {
                used[b] = true;
                cont++;
            }
            if(!used[c])
            {
                used[c] = true;
                cont++;
            }
        }
        while(scanf("%d %d", &start, &ttl) && start != 0)
        {
            int reachable = 1;
            int dist[100000];
            bool visited[100000] = {false};
            queue<int> q;
            q.push(start);
            dist[start] = 0;
            visited[start] = true;
            //cout<<"Case "<<cas<<endl;
            while(!q.empty())
            {
                int p = q.front();
                //cout<<"Visited "<<p<<endl;
                q.pop();
                for(int a = 0; a < graph[p].size(); a++)
                {
                    if(!visited[graph[p][a]])
                    {
                        dist[graph[p][a]] = dist[p]+1;
                        visited[graph[p][a]] = true;
                        if(dist[graph[p][a]] <= ttl)
                        {
                            reachable++;
                            q.push(graph[p][a]);
                        }

                    }
                }
            }
            //Case 1: 5 nodes not reachable from node 35 with TTL = 2.
            //cout<<"reachable "<<reachable<<endl;
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++cas, (cont - reachable), start, ttl);
        }
    }
    return 0;
}
