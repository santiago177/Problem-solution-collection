#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <utility>
#include <sstream>

using namespace std;

int main()
{
    //freopen("821 - Page Hopping.in", "r", stdin);
    //freopen("821 - Page Hopping.out", "w", stdout);
    string s;
    int l, k, c = 0;
    bool out;
    while(1)
    {
        out = false;
        vector<int> graph[101];
        int count = 0, pairs;
        set<int> nodesc;
        stringstream st(s);
        while(scanf("%d %d", &l, &k))
        {
            if(l == 0 && k == 0)
                break;
            nodesc.insert(l);
            nodesc.insert(k);
            graph[l].push_back(k);
            out = true;

        }
        if(!out)
            break;
        int iter = 0;
        for(set<int>::iterator pt = nodesc.begin(); pt != nodesc.end(); pt++)//int a = 1; a <= highest; a++)
        {
            //cout<<"!!!!!!!!!! "<<++iter<<endl;
            int lowest[101];
            for(set<int>::iterator it = nodesc.begin(); it != nodesc.end(); it++)/*int b = 1; b <= highest; b++)*/
            {
                lowest[*it]= 1000000000;
            }
            bool visited[101] = {0};
            lowest[*pt] = 0;
            int current = *pt;
            priority_queue<pair<int, int> > min;
            while(1)
            {
                //cout<<"current "<<current<<endl;
                visited[current] = true;
                for(int b = 0; b < graph[current].size(); b++)
                {
                    //cout<<"checking "<<graph[current][b]<<endl;
                    int hop = lowest[current]+1;
                    if(hop < lowest[graph[current][b]] && !visited[graph[current][b]])
                    {
                        lowest[graph[current][b]] = hop;
//                        dist[hop].push_back(graph[current][b]);
                        min.push(make_pair(-hop, graph[current][b]));
                    }
                }
                if(min.empty())
                    break;
                current = min.top().second;
                min.pop();
            }
            for(set<int>::iterator it = nodesc.begin(); it != nodesc.end(); it++)/*int b = 1; b <= highest; b++)*/
            {
               // cout<<"lowest "<<*it<<" "<<lowest[*it]<<endl;
                count += lowest[*it];
                //cout<<"!!!!!!!cont = "<<count<<endl;
            }
        }
        //cout<<"out"<<endl;
        pairs = nodesc.size()*(nodesc.size()-1);
        //cout<<"pairs "<<pairs<<" count "<<count<<endl;
        //Case 1: average length between pages = 1.833 clicks
        printf("Case %d: average length between pages = %.3lf clicks\n", ++c, (double)((double)count/(double)pairs));
        //cout<<"Case "<<++c<<": average length between pages = "<<count/
    }
    return 0;
}


