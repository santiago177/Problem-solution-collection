#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main()
{
    freopen("10048 - Audiophobia.in", "r", stdin);
    //freopen("10048 - Audiophobia.out", "w", stdout);
    int n, e, queries, cases = 0;
    while(cin>>n>>e>>queries)
    {

        if(n == 0 && e == 0  && queries == 0)
            break;
        vector<pair<int, int> >  graph[100];
        for(int a = 0; a < e; a++)
        {
            int q, w, r;
            //scanf("%d %d %d", &q)
            cin>>q>>w>>r;
            graph[q].push_back(make_pair(w, r));
            graph[w].push_back(make_pair(q, r));
        }
        //cout<<n<<" "<<e<<" "<<queries<<endl;
        if(cases != 0)
            cout<<endl;
        cout<<"Case #"<<++cases<<endl;
        for(int x = 0; x < queries; x++)
        {
            int lowest[100];
            map<int, int> inv;
            bool marked[100] = {0};
            bool out = false;
            memset(lowest, 10000, 100);
            int s, f;
            cin>>s>>f;
            lowest[s] = 0;
            if(graph[s].size() == 0)
            {
                cout<<"nopath"<<endl;
                continue;
            }
            int current = s;
            priority_queue<int> min;
            //cout<<"size "<<graph[s-1].size()<<endl;
            while(1)
            {
                //cout<<"check"<<endl;
                int val;
                marked[current] = true;
                for(int a = 0; a < graph[current].size(); a++)
                {

                    int dist = graph[current][a].second, node = graph[current][a].first, replace;
                    if(dist > lowest[current])
                    {
                        replace = dist;
                    }
                    else
                        replace = lowest[current];
                    if(!marked[node])
                    {
                        if(replace < lowest[node])
                        {
                            //cout<<"lowest de "<<node<<" = "<<replace<<endl;
                            lowest[node] = replace;
                            inv[replace] = node;
                        }
                        min.push(-lowest[node]);
                    }
                }
                if(out)
                    break;
                val = -min.top();
                min.pop();
                if(min.empty())
                    out = true;
                current = inv[val];
              //cout<<"check"<<endl;
//                for(int a = 0; a < n; a++)
//                {
//                    if(!marked[a] && lowest[a] == val)
//                    {
//                        current = a;
//                        break;
//                    }
//                }
            }
        if(marked[f])
            cout<<lowest[f]<<endl;
        else
            cout<<"nopath"<<endl;
        }
    }
    return 0;
}
