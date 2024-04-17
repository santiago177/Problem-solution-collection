#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <utility>

using namespace std;

pair<int, int> offset[4];

int main()
{
    freopen("garden.in", "r", stdin);
    offset[0] = make_pair(0, 1);
    offset[1] = make_pair(1, 0);
    offset[2] = make_pair(0, -1);
    offset[3] = make_pair(-1, 0);
    int n;
    cin>>n;
    for(int z = 0; z < n; z++)
    {
	int x, y, steps, cont = 0, nullen = 1, st;
	char matrix[108][108], dir, prev = '0', prev2 = '0';
	bool visited[108][108] = {0};
	for(int a = 0; a < 108; a++)
	    for(int b = 0; b < 108; b++)
		matrix[a][b] = '0';
	for(int a = 0; a < 108; a++)
	    matrix[0][a] = matrix[a][0] = matrix[107][a] = matrix[a][107] = '&';
	cin>>x>>y>>steps;
	x += 3;
	y += 3;
	for(int a = 0; a < steps; a++)
	{
	    //cout<<"x = "<<x<<" y = "<<y<<endl;
	    cin>>dir>>st;
	    if(dir == 'N')
	    {
		for(int b = y; b <= y+st+1; b++)
		{
		    //if(matrix[x][b] == '0')
		//	cont++;
		    matrix[x][b] = '1';
		}
		y += st+1;
		if(prev == 'N')
		    y--;
		if(prev == 'S')
		    prev = prev2;
		else
		{
		    prev2 = prev;
		    prev = 'N';
		}
	    }
	    if(dir == 'S')
	    {
		for(int b = y; b >= y-st-1; b--)
		{
		//    if(matrix[x][b] == '0')
		//	cont++;
		    matrix[x][b] = '1';
		}
		y -= st+1;
		if(prev == 'S')
		    y++;
		if(prev == 'N')
		    prev = prev2;
		else
		{
		    prev2 = prev;
		    prev = 'S';
		}
	    }
	    if(dir == 'E')
	    {
		for(int b = x; b <= x+st+1; b++)
		{
		 //   if(matrix[b][y] == '0')
		//	cont++;
		    matrix[b][y] = '1';
		}
		x += st+1;
		if(prev == 'E')
		    x--;
		if(prev == 'W')
		    prev = prev2;
		else
		{
		    prev2 = prev;
		    prev = 'E';
		}
	    }
	    if(dir == 'W')
	    {
		for(int b = x; b >= x-st-1; b--)
		{
		  //  if(matrix[b][y] == '0')
		//	cont++;
		    matrix[b][y] = '1';
		}
		x -= st+1;
		if(prev == 'W')
		    x++;
		if(prev == 'E')
		    prev = prev2;
		else
		{
		    prev2 = prev;
		    prev = 'W';
		}
	    }
	}
	queue<pair<int, int> > q;
	visited[1][1] = true;
	q.push(make_pair(1, 1));
	while(!q.empty())
	{
	    pair<int, int> p = q.front();
	    q.pop();
	    for(int a = 0; a < 4; a++)
	    {
		pair<int, int> t = make_pair(p.first+offset[a].first, p.second+offset[a].second);
		if(!visited[t.first][t.second] && matrix[t.first][t.second] == '0')
		{
		    visited[t.first][t.second] = true;
		    q.push(t);
		    nullen++;
		}
		if(!visited[t.first][t.second] && matrix[t.first][t.second] == '1')
		{
		    cont++;
		    visited[t.first][t.second] = true;
		}
	    }
	}
	cout<<"check"<<endl;
	for(int a = 0; a < 108; a++)
	{
	    	for(int b = 0; b < 108; b++)
		    cout<<matrix[a][b];
	    cout<<endl;
	}
	cout<<"zeroes = "<<nullen<<" cont = "<<cont<<endl;
	cout<<"Data Set "<<z+1<<": "<<106*106-nullen-cont<<" square feet."<<endl;
    }
    cout<<"End of Output\n";
    return 0;
}



