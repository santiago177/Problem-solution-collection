#include <iostream>
#include <stack>
#include <queue>
#include <cstdio>

using namespace std;

int main()
{
    //freopen("10009.in", "r", stdin);
    //freopen("10009.out", "w", stdout);
    int n;
    string gh;
    cin >> n;
    bool skip = false;
    for(int v = 0; v < n; v++)
    {
        getline(cin, gh);
        cin.ignore();
        bool used[30];
        int level[30];
        if(v != 0)
            cout<<endl;
        vector<int> graph[30];
        int e, abfrage;
        scanf("%d %d", &e, &abfrage);
        for(int b = 0; b < e; b++)
        {
            string c, f;
            //scanf("%s %s", c.c_str(), f.c_str());
            cin >> c >> f;
            graph[c[0]-'A'].push_back(f[0]-'A');
            graph[f[0]-'A'].push_back(c[0]-'A');
        }
        for(int b = 0; b < abfrage; b++)
        {

            for(int x = 0; x < 30; x++)
            {
                used[x] = false;
                level[x] = -1;
            }
            bool found = false;
            string c, f;
            cin >> c >> f;
            queue<int> q;
            q.push(c[0]-'A');
            used[c[0]-'A'] = true;
            level[c[0]-'A'] = 0;
            while(!q.empty() && !found)
            {
                int p = q.front();
                q.pop();
                for(int a = 0; a < graph[p].size() && !found; a++)
                {
                    if(!used[graph[p][a]])
                    {
                        level[graph[p][a]] = level[p]+1;
                        used[graph[p][a]] = true;
                        if(graph[p][a] == f[0]-'A')
                            found = true;
                        else
                            q.push(graph[p][a]);
                    }
                }
            }
            stack<int> weg;
            int h = level[f[0]-'A'];
            int temp = f[0]-'A';
            weg.push(f[0]-'A');
            while(h != 0)
            {
                for(int b = 0; b < graph[temp].size(); b++)
                {
                    if(level[graph[temp][b]] == h-1)
                    {
                        h--;
                        weg.push(graph[temp][b]);
                        temp = graph[temp][b];
                        break;
                    }
                }
            }
            while(!weg.empty())
            {
                cout<<(char)(weg.top()+'A');
                weg.pop();
            }
            cout<<endl;
        }
    }
    return 0;
}









