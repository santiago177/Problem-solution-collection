#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

void proc(vector<string> &board, pair<int, int> newp, int &rob, int &dest, int a, int b)
{
    if(board[newp.first][newp.second] != '.')
        {
            if(board[newp.first][newp.second] == '+' || board[newp.first][newp.second] == '#')
            {
                board[newp.first][newp.second] = '*';
                board[a][b] = '.';
                rob -= 2;
            }
            else if(board[newp.first][newp.second] == '@')
            {
                rob--;
                board[a][b] = '.';
                dest++;
            }
            else
            {
                rob--;
                board[a][b] = '.';
            }
        }
        else
        {
            board[newp.first][newp.second] = board[a][b];
            board[a][b] = '.';
        }
}

pair<int, int> move(vector<string> &board, int a, int b, const pair<int, int> &hero, int &rob, int & dest, queue<pair<int, int> > &fast, bool report)
{
    pair<int, int> newp;
//    cout<<"actual = "<<board[a][b]<<" ";
    if(a == hero.first)
    {
        if(b > hero.first)
            newp = make_pair(a, b-1);
        else
            newp = make_pair(a, b+1);
    }
    else if(b == hero.second)
    {
        if(a > hero.first)
            newp = make_pair(a-1, b);
        else
            newp = make_pair(a+1, b);
    }
    else
    {
        if(a > hero.first && b > hero.second)
            newp = make_pair(a-1, b-1);
        else if(a > hero.first && b < hero.second)
            newp = make_pair(a-1, b+1);
        else if(a < hero.first && b > hero.second)
            newp = make_pair(a+1, b-1);
        else
            newp = make_pair(a+1, b+1);
    }
    proc(board, newp, rob, dest, a, b);
//    cout<<"newp = "<<newp.first<<" "<<newp.second<<"("<<board[newp.first][newp.second]<<")"<<endl;
    if(board[newp.first][newp.second] == '#' && report)
    {
        fast.push(make_pair(newp.first, newp.second));
        newp = make_pair(-1, -1);
    }
    else if(board[newp.first][newp.second] == '*' || board[newp.first][newp.second] == '@')
    {
        newp = make_pair(-1, -1);
    }
//    cout<<"robs = "<<rob<<endl;
    return newp;
}

int main()
{
    //freopen("5054 - Killbots.in", "r", stdin);
    //string s;
    char s[1000];
    int size;
    size = scanf("%s", &s);
    while(size > 0)
    {
        string d = s;
        vector<string> board;
        int rob = 0, kills = 0;
        pair<int, int> hero;
        board.push_back(s);
        while(scanf("%s", &s))
        {
            char f = s[0];
            if(f == '$')
                break;
            d = s;
            board.push_back(d);
        }
        queue<pair<int, int> > bots, fast;
        for(int a = 0; a < board.size(); a++)
        {
            for(int b = 0; b < board[a].size(); b++)
            {
                if(board[a][b] == '@')
                    hero = make_pair(a, b);
                if(board[a][b] == '+' || board[a][b] == '#')
                {
                    bots.push(make_pair(a, b));
                    rob++;
                }
            }
        }
        while(rob)
        {
//                        for(int a = 0; a < board.size(); a++)
//            {
//                for(int b = 0; b < board[a].size(); b++)
//                    cout<<board[a][b];
//                cout<<endl;
//            }
//            cout<<endl;
            pair<int, int> p, h;
            queue<pair<int, int> >next;
            while(!bots.empty())
            {
                p = bots.front();
                bots.pop();
                if(board[p.first][p.second] == '*')
                    continue;
//                cout<<"P = "<<p.first<<" "<<p.second<<endl;
                h = move(board, p.first, p.second, hero, rob, kills, fast, true);
//                cout<<"H = "<<h.first<<" "<<h.second<<endl;
                if(h.first != -1 && h.second != -1)
                    next.push(h);
            }
            //int v = 1/0;
            while(!fast.empty())
            {
                p = fast.front();
                fast.pop();
                if(board[p.first][p.second] == '*')
                    continue;
//                cout<<"P = "<<p.first<<" "<<p.second<<endl;
                h = move(board, p.first, p.second, hero, rob, kills, fast, false);
//                cout<<"H = "<<h.first<<" "<<h.second<<endl;
                if(h.first != -1 && h.second != -1)
                    next.push(h);
            }
            bots = next;
        }
        cout<<kills<<endl;
        size = scanf("%s", &s);
    }
    return 0;
}







