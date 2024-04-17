#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    //cout<<"check"<<endl;
    freopen("11377 - Airport Setup.in", "r", stdin);
    vector<int> graph[2001];
    int j;
    cin>>j;
    for(int z = 0; z < j; z++)
    {
        if(z != 0)
            cout<<endl;
        bool flughafen[2001] = {false};
        int zaehler[2001] = {0};
        int n, m, k, abfragen;
        cin>>n>>m>>k;
        for(int a = 0; a < k; a++)
        {
            int t;
            cin>>t;
            flughafen[t] = true;
        }
        string temp;
        for(int a = 0; a < m; a++)
        {
            int c, t;
            cin>>c>>t;
            graph[c].push_back(t);
            graph[t].push_back(c);
        }
        cin>>abfragen;
        cout<<"Case "<<z+1<<":"<<endl;
        for(int a = 0; a < abfragen; a++)
        {

            bool besucht[2001] = {false}, special = false;;
            int anfang, ziel, menge = -1;
            cin>>anfang>>ziel;
            //cout<<anfang<<" "<<ziel<<endl;
            queue<int> s;
            priority_queue<int> pq;
            if(!flughafen[anfang])
                zaehler[anfang] = 1;
            else
                zaehler[anfang] = 0;
            if(anfang == ziel)
            {
                cout<<0<<endl;
                continue;
            }
            s.push(anfang);
            while(!s.empty())
            {
                int p = s.front();
                s.pop();
                for(int b = 0; b < graph[p].size(); b++)
                {
                    if(!besucht[graph[p][b]] && graph[p][b] == ziel)
                    {
                        if(!flughafen[ziel])
                        {
                            menge = zaehler[p] + 1;
                            pq.push(-menge);
                        }
                        else
                        {
                            menge = zaehler[p];
                            pq.push(-menge);
                        }
                    }
                    else if(!besucht[graph[p][b]] && !flughafen[graph[p][b]])
                    {
                        s.push(graph[p][b]);
                        zaehler[graph[p][b]] = zaehler[p] + 1;
                        besucht[graph[p][b]] = true;
                    }
                    else if(!besucht[graph[p][b]])
                    {
                        s.push(graph[p][b]);
                        zaehler[graph[p][b]] = zaehler[p];
                        besucht[graph[p][b]] = true;
                    }
                }

            }
            if(!pq.empty())
                menge = -pq.top();
            cout<<menge<<endl;
        }
    }
    return 0;
}












