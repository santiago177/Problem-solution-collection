#include <utility>
#include <iostream>
#include <stack>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
    //freopen("260 - Il Gioco dell'X.in", "r", stdin);
    //freopen("260 - Il Gioco dell'X.out", "w", stdout);
    int n, cas = 0;
    while(cin>>n && n != 0)
    {
        n+=2;
        char board[202][202];
        bool visited[202][202];
        bool win = false;
        for(int a = 0; a < n; a++)
            board[0][a] = board[a][0] = board[n-1][a] = board[a][n-1] =  '$';
        vector<pair<int, int> > w;
        for(int a = 1; a < n-1; a++)
        {
            for(int b = 1; b < n-1; b++)
            {
                cin>>board[a][b];
                visited[a][b] = false;
                if(board[a][b] == 'w' && b == 1)
                {
                    w.push_back(make_pair(a, b));
                    //cout<<a<<" "<<b<<" inserted"<<endl;
                }
            }
        }
        pair<int, int> offset[6];
        offset[0] = make_pair(-1, -1);
        offset[1] = make_pair(0, -1);
        offset[2] = make_pair(-1, 0);
        offset[3] = make_pair(1, 1);
        offset[4] = make_pair(0, 1);
        offset[5] = make_pair(1, 0);
        for(int a = 0; a < w.size() && !win; a++)
        {
            if(!visited[w[a].first][w[a].second])
            {
                stack<pair<int, int> > s;
                pair<int, int> t;
                s.push(make_pair(w[a].first, w[a].second));
                visited[w[a].first][w[a].second] = true;
                while(!s.empty())
                {
                    pair<int, int> p = s.top();
                    //cout<<"visited "<<p.first<<" "<<p.second<<endl;
                    //cout<<"TF "<<visited[p.first][p.second]<<endl;
                    if(p.second == n-2)
                                win = true;
                    for(int a = 0; a < 6; a++)
                    {
                        t.first = p.first + offset[a].first;
                        t.second = p.second + offset[a].second;
                        if(board[t.first][t.second] == 'w'&& !visited[t.first][t.second])
                        {
                            //cout<<"TF "<<visited[t.first][t.second]<<endl;
                            //cout<<"visited "<<t.first<<" "<<t.second<<endl;
                            s.push(t);
                            visited[t.first][t.second] = true;
                            break;
                        }
                    }
                    if(p == s.top())
                        s.pop();
                    if(win)
                        break;
                }
            }
        }
        win? cout<<++cas<<" W"<<endl:cout<<++cas<<" B"<<endl;
    }
    return 0;
}









