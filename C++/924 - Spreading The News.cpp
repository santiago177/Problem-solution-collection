#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
    //freopen("924 - Spreading The News.in", "r", stdin);
    //freopen("924 - Spreading The News.out", "w", stdout);
    vector<int> graph[2505];
    int daymax[2505];
    int level[2505];
    bool used[2505];
    int n;
    cin>>n;
    for(int a = 0; a < n; a++)
    {
        int na;
        cin>>na;
        for(int b = 0; b < na; b++)
        {
            int x;
            cin>>x;
            graph[a].push_back(x);
        }
    }
    int m;
    cin>>m;
    for(int a = 0; a < m; a++)
    {
        for(int b = 0; b < n; b++)
        {
            used[b] = false;
            daymax[b] = 0;
            level[b] = -1;
        }
        int query, ht = -1, hm = -1;
        cin>>query;
        queue<int> q;
        q.push(query);
        level[query] = 0;
        used[query] = true;
        while(!q.empty())
        {
            int p = q.front();
            q.pop();
            for(int b = 0; b < graph[p].size(); b++)
            {
                if(!used[graph[p][b]])
                {
                    level[graph[p][b]] = level[p]+1;
                    daymax[level[graph[p][b]]]++;
                    q.push(graph[p][b]);
                    used[graph[p][b]] = true;
                }
            }
        }
        for(int b = 1; b < n; b++)
        {
            if(daymax[b] > hm)
            {
                ht = b;
                hm = daymax[b];
            }
        }
        if(hm > 0)
        cout<<hm<<" "<<ht<<endl;
        else
        cout<<0<<endl;
    }
    return 0;
}



