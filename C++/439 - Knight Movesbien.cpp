#include <iostream>
#include <utility>
#include <queue>

using namespace std;
int main()
{
//    for(int a = 0; a < 12; a++)
//    {
//        for(int b = 0; b < 12; b++)
//            cout<<board[a][b]<<" ";
//        cout<<endl;
//    }
    string p1, p2;
    pair<int, int> offset[8];
    //(col, fil)
    offset[0] = make_pair(2, 1);
    offset[1] = make_pair(2, -1);
    offset[2] = make_pair(1, 2);
    offset[3] = make_pair(-1, 2);
    offset[4] = make_pair(1, -2);
    offset[5] = make_pair(-1, -2);
    offset[6] = make_pair(-2, -1);
    offset[7] = make_pair(-2, 1);
    while(cin >> p1 >> p2)
    {
        int board[12][12];
        for(int a = 2; a < 10; a++)
            for(int b = 1; b < 10; b++)
                board[a][b] = -1;
        for(int a = 0; a <12 ; a++)
            board[0][a] = board[11][a] = board[a][0] = board[a][11] = board[1][a] = board[10][a] = board[a][1] = board[a][10] = 7;
        int an;
        int s1 = p1[0]-'a'+2, s2 = p1[1] - '0' + 1;
        int r1 = p2[0]-'a'+2, r2 = p2[1] - '0' + 1;
        queue<pair<int, int> > q;
        q.push(make_pair(s1, s2));
        board[s1][s2] = 0;
        pair<int, int> heute(s1, s1), aux;
        while(!q.empty())
        {
            heute = q.front();
            if(heute.first == r1 && heute.second == r2)
            {
                an = board[r1][r2];
                break;
            }
            q.pop();
            for(int a = 0; a < 8; a++)
            {
                aux.first = heute.first + offset[a].first;
                aux.second = heute.second + offset[a].second;
                if(board[aux.first][aux.second] == -1)
                {
                    board[aux.first][aux.second] = board[heute.first][heute.second] + 1;
                    q.push(aux);
                }
            }
        }
        cout<<"To get from "<<p1<<" to "<<p2<<" takes "<<an<<" knight moves."<<endl;
    }
    return 0;
}
