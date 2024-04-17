#include <iostream>
//#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

class pair2
{
    public:
    char car;
    int val;
    pair2(char c, int v)
    {
        car = c;
        val = v;
    }
    bool operator<(const pair2 &p1) const
    {
        if(val < p1.val)
            return true;
        if(val == p1.val)
        {
            if(car > p1.car)
                return true;
            else
                return false;
        }
        return false;
    }
};

int main()
{
    //freopen("10336 - Rank the Languages.in", "r", stdin);
    //freopen("10336 - Rank the Languages.out", "w", stdout);
    pair<int, int> offset[4];
    offset[0] = make_pair(0, 1);
    offset[1] = make_pair(0, -1);
    offset[2] = make_pair(1, 0);
    offset[3] = make_pair(-1, 0);
    char board[28][28];
    bool visited[28][28];
    int n;
    cin>>n;
    for(int z = 0; z < n; z++)
    {
        priority_queue<pair2> pq;
        bool exists[26] = {false};
        string temp;
        int r, c;
        cin>>r>>c;
        r+=2;
        c+=2;
        for(int a = 0; a < c; a++)
            board[0][a] = board[a][0] = board[r-1][a] = board[a][c-1] = '@';
        //cout<<endl;
        for(int a = 1; a < r-1; a++)
        {
            cin>>temp;
            for(int b = 1; b < c-1; b++)
            {
                board[a][b] = temp[b-1];
                visited[a][b] = false;
                exists[board[a][b]-'a'] = true;
            }
        }
//        for(int a = 0; a < r; a++)
//        {
//            for(int b = 0; b < c; b++)
//            {
//                cout<<board[a][b];
//            }
//            cout<<endl;
//        }
        for(int a = 0; a < 26; a++)
        {
            if(exists[a])
            {
                //cout<<"current "<<(char)(a+'a')<<endl;
                int cont = 0;
                for(int b = 1; b < r+1; b++)
                {
                    for(int f =  1; f < c+1; f++)
                    {
                        if(board[b][f] == a + 'a' && !visited[b][f])
                        {
                            queue<pair<int, int> > q;
                            q.push(make_pair(b, f));
                            visited[b][f] = true;
                            while(!q.empty())
                            {
                                pair<int, int> p = q.front();
                                q.pop();
                                for(int d = 0; d < 4; d++)
                                {
                                    pair<int, int> t = make_pair(p.first+offset[d].first, p.second+offset[d].second);
                                    if(!visited[t.first][t.second] && board[t.first][t.second] == a+'a')
                                    {
                                        visited[t.first][t.second] = true;
                                        q.push(t);
                                    }
                                }
                            }
                            cont++;
                        }
                    }
                }
                pair2 p(a+'a', cont);
                pq.push(p);

            }
        }
        cout<<"World #"<<z+1<<endl;
        while(!pq.empty())
        {
            cout<<(char)pq.top().car<<": "<<pq.top().val<<endl;
            pq.pop();
        }
    }
    return 0;
}
