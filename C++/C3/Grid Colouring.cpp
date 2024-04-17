#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <map>
#include <queue>

using namespace std;

class dreituple
{
    public:
    int x, y;
    char buch;
    dreituple(int a, int b, char car)
    {
	x = a;
	y = b;
	buch = car;
    }
};

typedef dreituple dt;
typedef pair<int, int> pii;
pii offset[4];

void build()
{
    offset[0] = make_pair(1, 0);
    offset[1] = make_pair(0, 1);
    offset[2] = make_pair(-1, 0);
    offset[3] = make_pair(0, -1);
}

int main()
{
    //freopen("Grid Colouring.in", "r", stdin);
    build();:
    string s;
    while(getline(cin, s))
    {
	vector<string> grid;
	vector<dt> mism;
	bool visited[31][81] = {0};
	while(s[0] != '_')
	{
	    grid.push_back(s);
	    getline(cin, s);
	}	
	for(int a = 0; a < grid.size(); a++)
	    for(int b = 0; b < grid[a].size(); b++)
		if(grid[a][b] != ' ' && grid[a][b] != 'X')
		{
		    dt p(a, b, grid[a][b]);
		    mism.push_back(p);
		}
	
	for(int a = 0; a < mism.size(); a++)
	{
	    if(!visited[mism[a].x][mism[a].y])
	    {
		visited[mism[a].x][mism[a].y] = true;
		queue<pii> q;
		q.push(make_pair(mism[a].x, mism[a].y));
		while(!q.empty())
		{
		    pii p = q.front();
		    q.pop();
		    for(int b = 0; b < 4; b++)
		    {
			pii t = make_pair(p.first + offset[b].first, p.second + offset[b].second);
			if(grid[t.first][t.second] != 'X' && !visited[t.first][t.second])
			{
			    visited[t.first][t.second] = true;
			    grid[t.first][t.second] = mism[a].buch;
			    q.push(t);
			}
		    }
		}
	    }
	}
	for(int a = 0; a < grid.size(); a++)
	    cout<<grid[a]<<endl;
	cout<<"_____________________________"<<endl;
    }
    return 0;
}
