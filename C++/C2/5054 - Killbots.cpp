#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
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

void move(vector<string> &board, int a, int b, const pair<int, int> &hero, int &rob, int & dest, queue<pair<int, int> > &fast, bool report)
{
    pair<int, int> newp;
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
    if(board[newp.first][newp.second] == '#' && report)
        fast.push(make_pair(newp.first, newp.second));
}

int main()
{
    freopen("5054 - Killbots.in", "r", stdin);
    string s;
    while(cin>>s)
    {
        vector<string> board;
        pair<int, int> hero;
        bool first = true;
        board.push_back(s);
        int rob = 0, dest = 0;
        while(cin>>s && s != "$")
        {
            board.push_back(s);
        }
        for(int a = 0; a < board.size(); a++)
        {
            for(int b = 0; b < board[a].size(); b++)
            {
                if(board[a][b] == '@')
                    hero = make_pair(a, b);
                if(board[a][b] == '+' || board[a][b] == '#')
                    rob++;
            }
        }
        while(rob)
        {
//            for(int a = 0; a < board.size(); a++)
//            {
//                for(int b = 0; b < board[a].size(); b++)
//                    cout<<board[a][b];
//                cout<<endl;
//            }
            queue<pair<int, int> > fast;
            for(int a = 0; a < board.size(); a++)
            {
                for(int b = 0; b < board[a].size(); b++)
                {
                    if(board[a][b] == '+' || board[a][b] == '#')
                    {
                        move(board, a, b, hero, rob, dest, fast, true);
                    }
                }
            }
            while(!fast.empty())
            {
                move(board, fast.front().first, fast.front().second, hero, rob, dest, fast, false);
                fast.pop();
            }
//            cout<<"rob = "<<rob<<endl;
        }
        cout<<dest<<endl;
    }
    return 0;
}









