#include <iostream>
#include <cstdio>
#include <deque>
#include <sstream>
#include <utility>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

pii offset[4];

void fill()
{
    offset[0] = make_pair(1, 0);
    offset[1] = make_pair(0, 1);
    offset[2] = make_pair(-1, 0);
    offset[3] = make_pair(0, -1);
    offset[4] = make_pair(1, 1);
    offset[5] = make_pair(-1, -1);
    offset[6] = make_pair(1, -1);
    offset[7] = make_pair(-1, 1);
}

void print(vector<vector<bool> > cosa)
{
    for(int a = 0; a < cosa.size(); a++)
    {
	for(int b = 0; b < cosa[a].size(); b++)
	{
	    if(cosa[a][b])
		cout<<'T';
	    else
		cout<<'F';
	}
	cout<<endl;
    }
}

int suchen(deque<string> &grid, vector<vector<bool> >visited, int i, int j)
{
    int bereich = 0;
    queue<pii> q;
    q.push(make_pair(i, j));
    visited[i][j] = true;
    while(!q.empty())
    {
	//print(visited);
	//cout<<endl;
	bereich++;
	pii p = q.front();
	q.pop();
	for(int a = 0; a < 8; a++)
	{
	    pii t = make_pair(p.first + offset[a].first, p.second + offset[a].second);
	    if(grid[t.first][t.second] == 'W' && !visited[t.first][t.second]) 
	    {
		visited[t.first][t.second] = true;
		q.push(t);
	    }
	}
    }
    return bereich;
}

int main()
{
    fill();
    freopen("wetlands.in", "r", stdin);
    int n;
    cin>>n;
    cin.ignore();
    string s;
    getline(cin, s);
    for(int z = 0; z < n; z++)
    {
	int sx, sy;
	if(z != 0)
	    cout<<endl;
	deque<string> grid;
	while(1)
	{
	    getline(cin, s);
	    if(isdigit(s[0]) || s == "")
		break;
	    grid.push_back(s);
	    //cout<<"inserted "<<s<<endl;
	}
	sx = grid[0].size();
	sy = grid.size();
	for(int a = 0; a < grid.size(); a++)
	    grid[a] = "%" + grid[a] + "%";
	string append = "";
	for(int a = 0; a < grid[0].size(); a++)
	    append += '%';
	grid.push_front(append);
	grid.push_back(append);
	//for(int a = 0; a < grid.size(); a++)
	    //cout<<grid[a]<<endl;
	vector<vector<bool> > visited;
	for(int a = 0; a < grid.size(); a++)
	{
	    vector<bool> t(grid[0].size(), false);
	    visited.push_back(t);
	}
	while(1)
	{
	    if(s == "")
		break;
	    int i, j, ans;
	    stringstream ss(s);
	    //cout<<"s "<<s<<endl;
	    ss>>i>>j;
	    //cout<<"sizes "<<sx<<" "<<sy<<endl;
	    //cout<<"i "<<i<<" j "<<j<<" "<<grid[i][j]<<endl;
	    if(j <= 0 || i <= 0 ||j > sx || i > sy || grid[i][j] != 'W')
	    {
		cout<<0<<endl;
	    }
	    else
	    {
		//cout<<"in"<<endl;
		ans = suchen(grid, visited, i, j);
		cout<<ans<<endl;
	    }
	    if(!getline(cin, s))
		break;
	    if(s == "")
		break;
	}
    }
    return 0;
}

