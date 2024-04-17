#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <utility>

using namespace std;

int main()
{
    freopen("2089 - N-Credible Mazes.in", "r", stdin);
    int dim, cont = 0;
    while(cin>>dim && dim != 0)
    {
        bool out = false, possible = false;
        int temp;
        map<string, vector<string> > graph;
        vector<int> v1, v2;
        string start, end;
        start = end = "";
        for(int a = 0; a < dim; a++)
        {
            cin>>temp;
            start += temp + '0';
        }
        for(int a = 0; a < dim; a++)
        {
            cin>>temp;
            end += temp + '0';
        }
        while(1)
        {
            bool first = false, non = false;
            int t;
            string p1, p2;
            vector<int> v1, v2;
            p1 = p2 = "";
            for(int a = 0; a < dim && !out; a++)
            {
                cin>>t;
                if(t == -1)
                {
                    out = true;
                    break;
                }
                v1.push_back(t);
            }
            if(out)
                break;
            for(int a = 0; a < dim && !out; a++)
            {
                cin>>t;
                if(t == -1)
                {
                    out = true;
                    break;
                }
                v2.push_back(t);
            }
            for(int a = 0; a < dim && !non; a++)
            {
                if(abs(v1[a] - v2[a]) == 1 && !first)
                    first = true;
                else if((abs(v1[a] - v2[a]) == 1 && first) || (abs(v1[a] - v2[a]) > 1))
                    non = true;
            }
            if(non || !first)
                continue;
            for(int a = 0; a < dim; a++)
            {
                p1 += v1[a] + '0';
                p2 += v2[a] + '0';
            }
//            cout<<"p1 = "<<p1<<endl;
//            cout<<"p2 = "<<p2<<endl;
            graph[p1].push_back(p2);
            graph[p2].push_back(p1);
        }
    //            Maze #1 can be travelled
    //Maze #2 cannot be travelled
//    cout<<"check";
            cout<<"Maze #"<<++cont;
            map<pair<string, string>, bool> visited;
            queue<string> q;
            q.push(start);
//            cout<<"GRAPH '1'"<<endl;
//            for(int a =0; a < graph["1"].size(); a++)
//            {
//                //cout<<graph["1"][a]<<endl;
//            }
            while(!q.empty())
            {
                string p = q.front();
//                cout<<"current = "<<p<<endl;
                if(p == end)
                {
                    possible = true;
                    break;
                }
                q.pop();
                for(int a = 0; a < graph[p].size(); a++)
                {
//                    cout<<"checking "<<graph[p][a]<<endl;
                    if(visited.find(make_pair(p, graph[p][a])) == visited.end())
                    {
                        visited[make_pair(p, graph[p][a])] = true;
                        q.push(graph[p][a]);
//                        cout<<"inserted "<<graph[p][a]<<endl;
                    }
                }
            }
            if(possible)
                cout<<" can be travelled"<<endl;
            else
                cout<<" cannot be travelled"<<endl;
    }
    return 0;
}






