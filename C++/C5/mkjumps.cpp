#include <iostream>
#include <queue>
#include <utility>
#include <vector> 
#include <cstdio>

using namespace std;

typedef vector<vector<char> > vvc;
typedef pair<int, int> pii;

int minimum;

pii offset[8];

void init()
{
    offset[0] = make_pair(1, 2);
    offset[1] = make_pair(2, 1);
    offset[2] = make_pair(-1, 2);
    offset[3] = make_pair(2, -1);
    offset[4] = make_pair(1, -2);
    offset[5] = make_pair(-2, 1);
    offset[6] = make_pair(-1, -2);
    offset[7] = make_pair(-2, -1);
}

void print(vvc board)
{
    for(int a = 0; a < board.size(); a++)
    {
	for(int b = 0; b < board[a].size(); b++)
	    cout<<board[a][b];
	cout<<endl;
    }
}

bool check(pii p)
{
    if(p.first < 0 || p.second < 0)
	return false;
    if(p.first >= 10 || p.second >= 10)
	return false;
    return true;
}

void calc(int squares, vvc &board, pii start)
{
    squares--;
    board[start.first][start.second] = 'F';
    if(squares < minimum)
	minimum = squares;
    for(int a = 0; a < 8; a++)
    {
	pii t = make_pair(start.first + offset[a].first, start.second + offset[a].second);
	if(!check(t))
	    continue;
	if(board[t.first][t.second] == 'V')
	    calc(squares, board, t);
    }
}

int main()
{
    //freopen("mkjumps.out", "w", stdout);
    init();
    int n, squares, cas = 1;
    bool flag;
    pii start;
    while(cin >> n && n != 0)
    {
	minimum = 1<<30;
	squares = 0;
	flag = false;
	vvc board(10, vector<char>(10, '0'));
	for(int a = 0; a < n; a++)
	{
	    int s, x;
	    cin>>s>>x;
	    for(int b = s; b < s + x; b++)
	    {
		if(!flag)
		{
		    flag = true;
		    start = make_pair(a, b);
		}
		board[a][b] = 'V';
		squares++;
	    }
	}
	cout<<"Case "<<cas++<<", ";
	calc(squares, board, start);
	if(minimum == 1)
	    cout<<minimum<<" square can not be reached."<<endl;
	else
	    cout<<minimum<<" squares can not be reached."<<endl;
    }
    
    return 0;
}

