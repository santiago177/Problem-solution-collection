#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int target;

int DFS(vector<vector<char> > &grid, int x, int y)
{
    char a = '0', b = '0';
    grid[x][y] = 'y';
    int cont = 1;
    if(x-1 >= 0)
	a = grid[x-1][y];
    if(y-1 >= 0)
        b = grid[x][y-1];
    if(a == '*' || b == '*')
	return 1;
    if(x-1 >= 0)
        cont += DFS(grid, x-1, y);
    if(y-1 >= 0)
        cont += DFS(grid, x, y-1);
    return cont;
}
int main()
{
    int n;
    cin>>n;
    for(int z = 0; z < n; z++)
    {
	int r, c, m;
	cin>>r>>c>>m;
	vector<vector<char> >grid;
	for(int a = 0; a < r; a++)
	{
	    grid.push_back(vector<char>(c, '.'));
	}
	bool side = false, finish = false;;
	if(c < r)
	    side = true;
	int count = 0;
	target = (c*r)-m;
	if(side)
	{
	    for(int a = 0; a < r; a++)
	    {
		for(int b = 0; b < c; b++)
		{
		    if(count == m)
		    {
			finish = true;
			break;
    		    }
		    count++;
		    grid[a][b] = '*';
		}
		if(finish)
		    break;
	    }
	}
	else
	{
	    for(int a = 0; a < c; a++)
	    {
		for(int b = 0; b < r; b++)
		{
		    if(count == m)
		    {
			finish = true;
			break;
    		    }
		    count++;
		    grid[b][a] = '*';
		}
		if(finish)
		    break;
	    }
	}
	for(int a = 0; a < r; a++)
	{
	    for(int b = 0; b < c; b++)
	    {
		cout<<grid[a][b];
	    }
	    cout<<endl;
	}
	int t = DFS(grid, r-1, c-1);
	printf("Case #%d\n", z+1);
	if(t == target)
	{
	    grid[r-1][c-1] = 'c';
	    for(int a = 0; a < r; a++)
	    {
		for(int b = 0; b < c; b++)
		    cout<<grid[a][b];
		cout<<endl;
	    }
	}
	else
	{
	    cout<<"Impossible"<<endl;
	}
	for(int a = 0; a < r; a++)
	    {
		for(int b = 0; b < c; b++)
		    cout<<grid[a][b];
		cout<<endl;
	    }
    }
    return 0;
}



