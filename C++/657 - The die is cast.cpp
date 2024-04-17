#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    //freopen("657 - The die is cast.in", "r", stdin);
    //freopen("657 - The die is cast.out", "w", stdout);
    pair<int, int> offset1[4];
    offset1[0] = make_pair(0, 1);
    offset1[1] = make_pair(0, -1);
    offset1[2] = make_pair(1, 0);
    offset1[3] = make_pair(-1, 0);
//    offset1[4] = make_pair(1, 1);
//    offset1[5] = make_pair(1, -1);
//    offset1[6] = make_pair(-1, 1);
//    offset1[7] = make_pair(-1, -1);
    char image[50][50];
    bool besuch1[50][50];
    bool besuch2[50][50];
    int n, m;
    long cas = 0;
    bool skip = false;
    while(scanf("%d %d",&n,&m) && n!=0 && m!=0)
    {
        int counter = 0;
        vector<pair<int, int> > dices[50];
        priority_queue<int> val;
        string temp;
        for(int a = 0; a < m; a++)
        {
            cin>>temp;
            for(int b = 0; b < n; b++)
            {
                image[a][b] = temp[b];
                besuch1[a][b] = false;
                besuch2[a][b] = false;
            }
        }
        for(int a = 0; a < m; a++)
        {
            for(int b = 0; b < n; b++)
            {
                if((image[a][b] == '*' || image[a][b] == 'X') && !besuch1[a][b])
                {
                    queue<pair<int, int> > q;
                    q.push(make_pair(a, b));
                    besuch1[a][b] = true;
                    dices[counter].push_back(q.front());
                    while(!q.empty())
                    {
                        pair<int, int> p = q.front();
                        q.pop();
                        for(int a = 0; a < 4; a++)
                        {
                            pair<int, int> t = make_pair(p.first + offset1[a].first, p.second + offset1[a].second);
                            if((image[t.first][t.second] == '*' || image[t.first][t.second] == 'X') && !besuch1[t.first][t.second])
                            {
                                q.push(t);
                                dices[counter].push_back(t);
                                besuch1[t.first][t.second] = true;
                            }
                        }
                    }
                    ++counter;
                }
            }
        }
        for(int a = 0; a < counter; a++)
        {
            int cp = 0;
            for(int b = 0; b < dices[a].size(); b++)
            {
                if(image[dices[a][b].first][dices[a][b].second] == 'X' && !besuch2[dices[a][b].first][dices[a][b].second])
                {
                    cp++;
                    queue<pair<int, int> > q;
                    q.push(dices[a][b]);
                    besuch2[dices[a][b].first][dices[a][b].second] = true;
                    while(!q.empty())
                    {
                        pair<int, int> p = q.front();
                        q.pop();
                        for(int a = 0; a < 4; a++)
                        {
                            pair<int, int> t = make_pair(p.first + offset1[a].first, p.second + offset1[a].second);
                            if(image[t.first][t.second] == 'X' && !besuch2[t.first][t.second])
                            {
                                q.push(t);
                                besuch2[t.first][t.second] = true;
                            }
                        }
                    }
                }
            }
            val.push(-cp);
        }
//        if(cas != 0)
//            cout<<endl;
        cout<<"Throw "<<++cas<<endl;
        int s = val.size();
        if(s == 0)
            cout<<0;
        for(int a = 0; a < s; a++)
        {
            if(a == s-1)
            {
                cout<<-val.top();
                val.pop();
                break;
            }
            cout<<-val.top()<<" ";
            val.pop();
        }
        cout<<endl<<endl;
//        if(n!=0 && m!=0)
//            cout<<endl<<endl;
//        else
//        {
//            cout<<endl;
//            break;
//        }
    }
    return 0;
}

