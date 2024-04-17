#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

//void print_table(int *weight, int nodes)
//{
//    cout<<"TABLE"<<endl;
//    for(int a = 0; a < nodes; a++)
//        cout<<a<<" "<<weight[a]<<endl;
//}

int main()
{
    //freopen("10986 - Sending email.in", "r", stdin);
    int q;
    int n, m, s ,t;
    cin>>q;
    for(int z = 0; z < q; z++)
    {
        vector<pair<int, int> > graph[20000];
        bool visited[200000] = {0};
        int weight[200000];
        int p1, p2, d;
        scanf("%d %d %d %d", &n, &m, &s, &t);
        //cin>>n>>m>>s>>t;
        for(int a = 0; a < m; a++)
        {
            scanf("%d %d %d", &p1,&p2,&d);
            //cin>>p1>>p2>>d;
            graph[p1].push_back(make_pair(p2, d));
            graph[p2].push_back(make_pair(p1, d));
            weight[p1] = weight[p2] = 2000000000;
        }
        priority_queue<pair<int, int> > min;
        int current = s, dist;
        weight[s] = 0;
        while(1)
        {
            //cout<<"current "<<current<<endl;
            visited[current] = true;
            if(current == t) break;
            for(int a = 0; a < graph[current].size(); a++)
            {
                pair<int, int> p = graph[current][a];
                dist = weight[current]+p.second;
                if(!visited[p.first] && dist < weight[p.first])
                {
                    min.push(make_pair(-dist, p.first));
                    weight[p.first] = dist;
                }
            }
            //print_table(weight, n);
            if(min.empty())
                    break;
            //cout<<"first "<<min.top().first<<" second "<<min.top().second<<endl;
            current = min.top().second;
            min.pop();
        }
//        Case #1: 100
//Case #2: 150
//Case #3: unreachable
        if(!visited[t])
            cout<<"Case #"<<z+1<<": unreachable"<<endl;
        else
            cout<<"Case #"<<z+1<<": "<<weight[t]<<endl;
    }
    return 0;
}















