#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <utility>

using namespace std;

string direction(int a)
{
    if(a == 0)
        return "right";
    else if(a == 1)
        return "left";
    else if(a == 2)
        return "back";
    else
        return "forth";
}

int main()
{
    //freopen("Marcus, help!.in", "r", stdin);
    pair<int, int> offset[4];
    offset[0] = make_pair(0, 1);
    offset[1] = make_pair(0, -1);
    offset[2] = make_pair(1, 0);
    offset[3] = make_pair(-1, 0);
    char cell[10][10];
    int n;
    cin>>n;
    for(int z = 0; z < n; z++)
    {
        int x, y;
        pair<int, int> start;
        cin>>x>>y;
        x+=2;
        y+=2;
        for(int a = 0; a < y; a++)
            cell[0][a] = cell[a][0] = cell[x-1][a] = cell[a][y-1] = 'X';
        for(int a = 1; a < x-1; a++)
        {
            string temp;
            cin >> temp;
            for(int b = 1; b < y-1; b++)
            {
                cell[a][b] = temp[b-1];
                if(cell[a][b] == '@')
                    start = make_pair(a, b);
            }
        }
//        for(int a = 0; a < x; a++)
//        {
//            for(int b = 0; b < y; b++)
//            {
//                cout<<cell[a][b];
//            }
//            cout<<endl;
//        }
        bool out = false;
        queue<string> richtung;
        queue<pair<int, int> > q;
        //cout<<"start "<<cell[start.first][start.second]<<endl;
        q.push(start);
        while(!q.empty())
        {
            pair<int, int> p = q.front();
            //cout<<cell[p.first][p.second]<<endl;
            q.pop();
            for(int a = 0; a < 4; a++)
            {
                pair<int, int> t = make_pair(p.first+offset[a].first, p.second+offset[a].second);
                if(cell[p.first][p.second] == '@' && cell[t.first][t.second] == 'I')
                {
                    //cout<<cell[t.first][t.second]<<endl;
                    q.push(t);
                    richtung.push(direction(a));
                }
                if(cell[p.first][p.second] == 'I' && cell[t.first][t.second] == 'E')
                {
                    //cout<<cell[t.first][t.second]<<endl;
                    q.push(t);
                    richtung.push(direction(a));
                }
                if(cell[p.first][p.second] == 'E' && cell[t.first][t.second] == 'H')
                {
                    //cout<<cell[t.first][t.second]<<endl;
                    q.push(t);
                    richtung.push(direction(a));
                }
                if(cell[p.first][p.second] == 'H' && cell[t.first][t.second] == 'O')
                {
                    //cout<<cell[t.first][t.second]<<endl;
                    q.push(t);
                    richtung.push(direction(a));
                }
                if(cell[p.first][p.second] == 'O' && cell[t.first][t.second] == 'V')
                {
                    //cout<<cell[t.first][t.second]<<endl;
                    q.push(t);
                    richtung.push(direction(a));
                }
                if(cell[p.first][p.second] == 'V' && cell[t.first][t.second] == 'A')
                {
                    //cout<<cell[t.first][t.second]<<endl;
                    q.push(t);
                    richtung.push(direction(a));
                }
                if(cell[p.first][p.second] == 'A' && cell[t.first][t.second] == '#')
                {
                    //cout<<cell[t.first][t.second]<<endl;
                    richtung.push(direction(a));
                    out = true;
                    break;
                }
            }
            if(out)
                break;
        }
        //cout<<"check "<<richtung.size()<<endl;
        while(!richtung.empty())
        {
            richtung.size()!=1?cout<<richtung.front()<<" ":cout<<richtung.front()<<endl;
            richtung.pop();
        }
    }

    return 0;
}






