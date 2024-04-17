#include <iostream>
#include <vector>
#include <cstdio>
#include <stack>
#include <sstream>

using namespace std;

int main()
{
    cout<<"check"<<endl;
    freopen("11377 - Airport Setup.in", "r", stdin);
    int j;
    cin>>j;
    for(int z = 0; z < j; z++)
    {
        vector<int> graph[2001];
        cout<<"check"<<endl;
        bool flughafen[2001] = {false};
        int zaehler[2001] = {0};
        int n, m, k, abfragen;
//        for(int a = 0; a < k; a++)
//        {
//            int t;
//            cin>>t;
//            flughafen[t] = true;
//        }
        string temp;
        int t;
        cin>>temp;
        stringstream st(temp);
        while(st >> t)
        {
            cout<<"check"<<endl;
            flughafen[t] = true;
        }
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

            bool besucht[2001] = {false}, finden = false;
            int anfang, ziel, menge = -1;
            cin>>anfang>>ziel;
            stack<int> s;
            s.push(anfang);
            while(!s.empty() && !finden)
            {
                int p = s.top();
                for(int b = 0; b < graph[p].size() && !finden; b++)
                {
                    if(!besucht[graph[b][p]] && graph[b][p] == ziel)
                    {
                        finden = true;
                        if(!flughafen[ziel])
                            menge = zaehler[p] + 1;
                        else
                            menge = zaehler[p];
                    }
                    else if(!besucht[graph[b][p]] && !flughafen[graph[b][p]])
                    {
                        s.push(graph[b][p]);
                        zaehler[graph[b][p]] = zaehler[p] + 1;
                        besucht[graph[b][p]] = true;
                        break;
                    }
                    else if(!besucht[graph[b][p]])
                    {
                        s.push(graph[b][p]);
                        zaehler[graph[b][p]] = zaehler[p];
                        besucht[graph[b][p]] = true;
                        break;
                    }
                    else if(b == graph[p].size()-1)
                        s.pop();
                }
            }
            cout<<menge<<endl;
        }
    }
    return 0;
}












