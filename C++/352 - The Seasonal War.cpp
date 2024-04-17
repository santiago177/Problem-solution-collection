#include <iostream>
#include <queue>
#include <cstdio>
#include <utility>

using namespace std;

void BFS(int grid[][30], bool visited[][30], pair<int, int> start)
{
    pair<int, int> offset[8];
    offset[0] = make_pair(0, 1);
    offset[1] = make_pair(0, -1);
    offset[2] = make_pair(1, 0);
    offset[3] = make_pair(-1, 0);
    offset[4] = make_pair(1, 1);
    offset[5] = make_pair(1, -1);
    offset[6] = make_pair(-1, 1);
    offset[7] = make_pair(-1, -1);
    queue<pair<int, int> > q;
    q.push(start);
    visited[start.first][start.second] = true;
    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        for(int a = 0; a < 8; a++)
        {
            pair<int, int> t = make_pair(p.first+offset[a].first, p.second+offset[a].second);
            if(grid[t.first][t.second] == 1 && !visited[t.first][t.second])
            {
                q.push(t);
                visited[t.first][t.second] = true;
            }
        }
    }
}

int main()
{
    //freopen("352 - The Seasonal War.in", "r", stdin);
    int grid[30][30];
    bool visited[30][30];
    int m;
    bool skip = false;
    int cas = 0;
    while(cin>>m)
    {
        m+=2;
        string temp;
        for(int a = 0; a < m; a++)
            grid[0][a] = grid[a][0] = grid[m-1][a] = grid[a][m-1] = -1;
        for(int a = 1; a < m-1; a++)
        {
            cin>>temp;
            for(int b = 1; b < m-1; b++)
            {
                grid[a][b] = (int)(temp[b-1]-'0');
                visited[a][b] = false;
            }
        }
//        for(int a = 0; a < m; a++)
//        {
//            for(int b = 0; b < m; b++)
//                cout<<grid[a][b];
//            cout<<endl;
//        }
        int ans = 0;
        for(int a = 1; a < m-1; a++)
        {
            for(int b = 1; b < m-1; b++)
            {
                //cout<<"grid "<<grid[a][b]<<"visited "<<visited[a][b]<<endl;
                if(grid[a][b] == 1 && !visited[a][b])
                {

                    BFS(grid, visited, make_pair(a, b));
                    ans++;
                    //cout<<"visited "<<visited[a][b]<<endl;
                }
            }
        }
        //Image number 1 contains 3 war eagles.
        cout<<"Image number "<<++cas<<" contains "<<ans<<" war eagles."<<endl;
    }
    return 0;
}
