#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <stack>
#include <utility>

using namespace std;

int conv(int size)
{
    if(size == 3 || size == 4)
        return 1;
    else if(size == 5)
        return 2;
    else if(size == 6)
        return 3;
    else if(size == 7)
        return 5;
    else
    return 11;
}

int main()
{
    freopen("11283 - Playing Boggle.in", "r", stdin);
    freopen("11283 - Playing Boggle.out", "w", stdout);
    pair<int, int> offset[8];
    offset[0] = make_pair(0, 1);
    offset[1] = make_pair(0, -1);
    offset[2] = make_pair(1, 0);
    offset[3] = make_pair(-1, 0);
    offset[4] = make_pair(1, 1);
    offset[5] = make_pair(1, -1);
    offset[6] = make_pair(-1, -1);
    offset[7] = make_pair(-1, 1);
    char board[6][6];
    bool check[6][6];
    int position[6][6];
    pair<string, bool> dictionary[100];
    for(int a = 0; a < 6; a++)
        board[0][a] = board[a][0] = board[5][a] = board[a][5] = 'ß';
    int n, m;
    scanf("%d", &n);

    for(int z = 0; z < n; z++)
    {
        int score = 0;
        cin.ignore();
        for(int a = 1; a < 5; a++)
        {
            string temp;
            cin>>temp;
            for(int b = 1; b < 5; b++)
            {
                board[a][b] = temp[b-1];
                check[a][b] = false;
            }
        }

        cin>>m;
        cout<<m<<endl;
        for(int a = 0; a < m; a++)
        {
            memset(*check, false, 36);
            bool notfound = false;
            string temp;
            cin>>temp;
            cout<<temp<<endl;
            dictionary[a] = make_pair(temp, false);
            for(int b = 1; b < 5 && !notfound; b++)
            {
                for(int c = 1; c < 5 && !notfound; c++)
                {
                    if(board[b][c] == temp[0] && !dictionary[a].second)
                    {
                        bool found = false;
                        stack<pair<int, int> > s;
                        s.push(make_pair(b, c));
                        check[b][c] = true;
                        position[b][c] = 1;
                        while(!s.empty() && !found && !notfound)
                        {
                            cout<<"asdas"<<endl;
                            cout<<"position "<<position[s.top().first][s.top().second]<<endl;
                            cout<<"current "<<board[s.top().first][s.top().second]<<endl<<"target "<<temp[position[s.top().first][s.top().second]]<<endl;
                            cout<<"init "<<s.top().first<<" "<<s.top().second<<endl;
                            for(int d = 0; d < 8 && !found; d++)
                            {
                                cout<<"d "<<d<<endl;
                                cout<<"position in "<<position[s.top().first][s.top().second]<<" size "<<temp.size()<<endl;
                                pair<int, int> t = make_pair(s.top().first+offset[d].first, s.top().second+offset[d].second);
                                cout<<t.first<<" "<<t.second<<" "<<board[t.first][t.second]<<endl;
                                if(board[t.first][t.second] == temp[position[s.top().first][s.top().second]] && !check[t.first][t.second] && position[s.top().first][s.top().second] == temp.size()-1)
                                {
                                    cout<<"found "<<temp<<endl;
                                    found = true;
                                    score += conv(temp.size());
                                    dictionary[a].second = true;
                                }
                                else if(board[t.first][t.second] == temp[position[s.top().first][s.top().second]] && !check[t.first][t.second])
                                {
                                    position[t.first][t.second] = position[s.top().first][s.top().second] +1;
                                    s.push(t);
                                    cout<<"inserted "<<board[t.first][t.second]<<endl;
                                    cout<<"position in "<<position[s.top().first][s.top().second]<<endl;
                                    check[t.first][t.second] = true;
                                    cout<<"creck"<<endl;
                                    break;
                                }
                                else if(d == 7)
                                {
                                    if(temp[position[s.top().first][s.top().second]] == board[s.top().first][s.top().second])
                                    check[s.top().first][s.top().second] = false;
                                    s.pop();
                                }
                                cout<<"pass"<<endl;
                            }
                        }
                    }
                }
            }
        }

        //Score for Boggle game #1: 6
        cout<<"Score for Boogle game #"<<z+1<<": "<<score<<endl;
    }
    return 0;
}













