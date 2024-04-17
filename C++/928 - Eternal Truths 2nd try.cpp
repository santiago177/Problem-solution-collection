#include <cstring>
#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

int main()
{
//    freopen("928 - Eternal Truths.in", "r", stdin);
//    freopen("928 - Eternal Truths.out", "w", stdout);
    pair<int, int> offset[4];
    offset[0] = make_pair(0, 1);
    offset[1] = make_pair(0, -1);
    offset[2] = make_pair(1, 0);
    offset[3] = make_pair(-1, 0);
    char grid[315][315];
    int n;
    scanf("%d", &n);
    for(int z = 0; z < n; z++)
    {
        //cout<<"CASE "<<z+1<<" !!!!!!!!!!!!!!!!!!!"<<endl;
        int level[3][315][315];
        bool states[3][315][315];
        memset(*states, false, 3*315*315);
        int r, c;
        scanf("%d %d", &r, &c);
        for(int a = 0; a < r+6; a++)
            grid[0][a] = grid[a][0] = grid[1][a] = grid[a][1] = grid[2][a] = grid[a][2] = grid[r+3][a] = grid[a][c+3] = grid[r+4][a] = grid[a][c+4] = grid[r+5][a] = grid[a][c+5] = '#';
        pair<int, int> start;
        for(int a = 3; a < r+3; a++)
        {
            char temp[315];
            scanf("%s", &temp);
            for(int b = 3; b < c+3; b++)
            {
                grid[a][b] = temp[b-3];
                if(grid[a][b] == 'S')
                start = make_pair(a, b);
            }
        }
        queue< pair<int, pair<int, int> > >q;
        int fin = 0;
        bool out = false;
        q.push(make_pair(0, start));
        level[2][start.first][start.second] = 0;
        states[0][start.first][start.second];
        while(!q.empty())
        {
            pair<int, pair<int, int> >p = q.front();
            q.pop();
            //cout<<"current "<<p.second.first<<" "<<p.second.second<<endl;
            for(int a = 0; a < 4; a++)
            {
                pair<int, int> t;
                if(p.first == 0)
                {
                    //cout<<"check1"<<endl;
                    t = make_pair(p.second.first+offset[a].first, p.second.second+offset[a].second);
                    //cout<<t.first<<" "<<t.second<<endl;
                    if(grid[t.first][t.second] == '#')
                        continue;
                    if((grid[t.first][t.second] == '.' || grid[t.first][t.second] == 'S') && !states[0][t.first][t.second])
                    {
                        level[0][t.first][t.second] = level[2][p.second.first][p.second.second]+1;
                        states[0][t.first][t.second] = true;
                        q.push(make_pair(1, t));
//                        cout<<"inserted "<<t.first<<" "<<t.second<<endl;
                    }
                    if(grid[t.first][t.second] == 'E')
                    {
                        fin = level[2][p.second.first][p.second.second] + 1;
                        out = true;
                        break;
                    }
                }
                else if(p.first == 1)
                {
//                    cout<<"check2"<<endl;
                    t = make_pair(p.second.first, p.second.second);
                    for(int b = 0; b < 2; b++)
                    {
                        t.first += offset[a].first;
                        t.second += offset[a].second;
//                        cout<<"b "<<b<<" a "<<a<<endl;
//                        cout<<t.first<<" "<<t.second<<endl;
                        if(grid[t.first][t.second] == '#')
                            break;
                        if((grid[t.first][t.second] == '.' || grid[t.first][t.second] == 'S' ) && !states[1][t.first][t.second] && b == 1 && grid[t.first][t.second]!='E')
                        {
                            level[1][t.first][t.second] = level[0][p.second.first][p.second.second]+1;
                            states[1][t.first][t.second] = true;
                            q.push(make_pair(2, t));
//                            cout<<"inserted "<<t.first<<" "<<t.second<<endl;
                        }
                        if(grid[t.first][t.second] == 'E' && b == 1)
                        {
                            fin = level[0][p.second.first][p.second.second] + 1;
                            out = true;
                            break;
                        }
                    }
                }
                else
                {
//                    cout<<"check3"<<endl;
                    t = make_pair(p.second.first, p.second.second);
                    for(int b = 0; b < 3; b++)
                    {
                        t.first += offset[a].first;
                        t.second += offset[a].second;
//                        cout<<"b "<<b<<" a "<<a<<endl;
//                        cout<<t.first<<" "<<t.second<<endl;
                        if(grid[t.first][t.second] == '#')
                            break;
                        if((grid[t.first][t.second] == '.' || grid[t.first][t.second] == 'S' ) && !states[2][t.first][t.second] && b == 2 && grid[t.first][t.second] != 'E')
                        {
                            level[2][t.first][t.second] = level[1][p.second.first][p.second.second] +1;
                            states[2][t.first][t.second] = true;
                            q.push(make_pair(0, t));
//                            cout<<"inserted "<<t.first<<" "<<t.second<<endl;
                        }
                        if(grid[t.first][t.second] == 'E' && b == 2)
                        {
                            fin = level[1][p.second.first][p.second.second] + 1;
                            out = true;
                            break;
                        }
                    }
                }
                if(out)
                    break;
            }
            if(out)
                break;
        }
        out?printf("%d\n", fin):printf("NO\n");
    }
    return 0;
}










