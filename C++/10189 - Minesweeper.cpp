#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

int main()
{
    //freopen("10189 - Minesweeper.in", "r", stdin);
    pair<int, int> offset[8];
    offset[0] = make_pair(0, 1);
    offset[1] = make_pair(0, -1);
    offset[2] = make_pair(1, 0);
    offset[3] = make_pair(-1, 0);
    offset[4] = make_pair(1, 1);
    offset[5] = make_pair(1, -1);
    offset[6] = make_pair(-1, 1);
    offset[7] = make_pair(-1, -1);
    char square[150][150];
    char def[150][150];
    int n, m, field = 0;
    while(cin>>n>>m)
    {
        memset(square, 0, 150*150);
        if(n == 0 && m == 0)
            break;
        bool visited[105][105];
        int st1, st2;
        for(int a = 0; a < n+2; a++)
            square[0][a] = square[a][0] = square[n+1][a] = square[a][m+1] = '$';
        for(int a = 1; a < n+1; a++)
        {
            for(int b = 1; b < m+1; b++)
            {
                cin>>square[a][b];
                visited[a][b] = false;
                if(square[a][b] == '*')
                {
                    def[a][b] = '*';
                }
            }
        }
        if(field != 0)
            cout<<endl;
        for(int a = 1; a < n+1; a++)
        {
            for(int b = 1; b < m+1; b++)
            {
                if(square[a][b] == '.' && !visited[a][b])
                {
                    queue<pair<int, int> > q;
                    q.push(make_pair(a, b));
                    while(!q.empty())
                    {
                        pair<int, int> p = q.front();
                        q.pop();
                        int cont = 0;
                        for(int a = 0; a < 8; a++)
                        {
                            pair<int, int> t = make_pair(p.first+offset[a].first,p.second+offset[a].second);
                            if(square[t.first][t.second] == '*')
                            {
                                cont++;
                            }
                            if(square[t.first][t.second] == '.' && !visited[t.first][t.second])
                            {
                                visited[t.first][t.second] = true;
                                q.push(t);
                            }
                        }
                        def[p.first][p.second] = cont+'0';
                    }
                }
            }
        }

        //Field #x:
        cout<<"Field #"<<++field<<":"<<endl;
        for(int a = 1; a < n+1; a++)
        {
            for(int b = 1; b < m+1; b++)
            {
                cout<<def[a][b];
            }
            cout<<endl;
        }
//        cout<<endl;
    }
    return 0;
}


