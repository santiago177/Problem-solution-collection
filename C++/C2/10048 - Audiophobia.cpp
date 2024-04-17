#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

class edge
{
    public:
    int w, s, e;
    edge(int p, int s1, int t1)
    {
        w = p;
        s = s1;
        e = t1;
    }
    bool operator < (const edge &o) const
    {
        return w < o.w;
    }
};

int main()
{
    freopen("10048 - Audiophobia.in", "r", stdin);
    int c, s, qr, cur = 0;
    while(scanf("%d %d %d", &c, &s, &qr) && c != 0)
    {
        int s1, s2, d;
        int i, f, nodes = 1;
        int graph[101][101] = {0}, highest[101];
        bool ins[101] = {0};
        vector<pair<int, int> > mst[101];
        priority_queue<edge> pq;
        cout<<"Case #"<<++cur<<endl;
        for(int a = 0; a < s; a++)
        {
            scanf("%d %d %d", &s1, &s2, &d);
            graph[s1][s2] = d;
            graph[s2][s1] = d;
            pq.push(edge(-d, s1, s2));
        }
        //kruskal
        edge t = pq.top();
        mst[t.s].push_back(make_pair(t.e, -t.w));
        mst[t.e].push_back(make_pair(t.s, -t.w));
        ins[t.s] = true;
        ins[t.e] = true;
        cout<<"t.e "<<t.e<<" t.s "<<t.s<<endl;
        while(nodes != c-1)
        {
            priority_queue<edge> npq;
            for(int a = 1; a <= c; a++)
            {
                if(ins[a])
                {
                    for(int b = 1; b <= c; b++)
                    {
                        if(graph[a][b] != 0)
                            npq.push(edge(-graph[a][b], a, b));
                    }
                }
            }
            while(!npq.empty())
            {
                t = npq.top();
                npq.pop();
                if(ins[t.s] ^ ins[t.e])
                {
                    ins[t.s] = true;
                    ins[t.e] = true;
                    nodes++;
                    mst[t.s].push_back(make_pair(t.e, -t.w));
                    mst[t.e].push_back(make_pair(t.s, -t.w));
                    break;
                }
            }
        }
//        for(int z = 0; z < qr; z++)
//        {
//            scanf("%d %d", &i, &f);
//        }
//        for(int a = 1; a <= c; a++)
//        {
//            cout<<a<<endl;
//            for(int b = 0; b < mst[a].size(); b++)
//                cout<<" "<<mst[a][b].first<<" "<<mst[a][b].second<<endl;
//        }
        for(int k = 0; k < qr; k++)
        {
            bool visited[101] = {0};
            scanf("%d %d", &s1, &s2);
            queue<int> q;
            q.push(s1);
            highest[s1] = 0;
            visited[s1] = true;
            while(!q.empty())
            {
                int p = q.front();
                if(p == s2)
                    break;
                q.pop();
                for(int a = 0; a < mst[p].size(); a++)
                {
                    pair<int, int> g = mst[p][a];
                    if(!visited[g.first])
                    {
                        q.push(g.first);
                        if(g.second > highest[p])
                            highest[g.first] = g.second;
                        else
                            highest[g.first] = highest[p];
                    }
                }
            }
            cout<<highest[s2]<<endl;
        }
        //int v = 1/0;
    }
    return 0;
}












