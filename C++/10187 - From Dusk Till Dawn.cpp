#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <utility>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int z = 0; z < n; z++)
    {
        map<string, vector<pair<string, pair<int, int> > > > graph;
        map<string, map<pair<string, pair<int, int> >, bool> > visited;
        map<string, map<pair<string, pair<int, int> >, pair <int, int> > > abreise;
        map<string, map<pair<string, pair<int, int> >, int> > strecke;
        graph["Dresden"].push_back(make_pair("Kiel",make_pair(1, 3)));
        //cout<<graph["Dresden"]["Kiel"][0].first<<" "<<graph["Dresden"]["Kiel"][0].second<<endl;
        int k;
        cin>>k;
        for(int a = 0; a < k; a++)
        {
            char t1[32], t2[32];
            int h1, h2;
            scanf("%s %s %d %d", t1, t2, &h1, &h2);
            graph[t1].push_back(make_pair(t2, make_pair(h1, h2)));
            visited[t1][make_pair(t2, make_pair(h1, h2))] = false;
            strecke[t1][make_pair(t2, make_pair(h1, h2))] = -1;
            abreise[t1][make_pair(t2, make_pair(h1, h2))] = make_pair(-1, -1);
        }
        char q1[32], q2[32];
        scanf("%s %s", q1, q2);
        queue<string> q;
        q.push(q1);
        int count = 0;
        while(!q.empty())
        {
            string p = q.front();
            q.pop();
            for(int a = 0; a < graph[p].size(); a++)
            {
                if(graph[p][a].second.first >= 18 && graph[p][a].second.first+graph[p][a].second.second % 24 <= 6 && !visited[t1][graph[p][a]])
                {
                    visited[p][graph[p][a]] = true;
                    q.push(graph[p][a].first);
                }
            }
        }
    }
    return 0;
}










