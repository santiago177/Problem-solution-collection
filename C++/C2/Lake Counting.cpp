#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

pair<int, int> offset[8];

int main()
{
    offset[0] = make_pair(0, 1);
    offset[1] = make_pair(0, -1);
    offset[2] = make_pair(1, 0);
    offset[3] = make_pair(-1, 0);
    offset[4] = make_pair(1, 1);
    offset[5] = make_pair(1, -1);
    offset[6] = make_pair(-1, 1);
    offset[7] = make_pair(-1, -1);
    queue<pair<int, int> > q;
    //freopen("Lake Counting.in", "r", stdin);
    int n, m, cont = 0;
    cin>>n>>m;
    char matrix[102][102] = {0};
    bool visited[102][102] = {0};
    memset(matrix, '$', 102*102);
    for(int a = 0; a < n; a++)
    {
	string temp;
	cin>>temp;
	for(int b = 0; b < m; b++)
	    matrix[a+1][b+1] = temp[b];
    }
//    for(int a = 0; a < n+2; a++)
//    {
//	for(int b = 0;b < m+2; b++)
//	    cout<<matrix[a][b];
//	cout<<endl;
//    }
    for(int a = 1; a < n+1; a++)
    {
	for(int b = 1; b < m+1; b++)
	{
	    if(matrix[a][b] == 'W' && !visited[a][b])
	    {
		cont++;
		queue<pair<int, int> > q;
		q.push(make_pair(a, b));
		visited[a][b] = true;
		while(!q.empty())
		{
		    pair<int, int> p = q.front();
		    int v = p.first;
		    int w = p.second; 
		    q.pop();
		    for(int c = 0; c < 8; c++)
		    {
			pair<int, int> t = make_pair(v + offset[c].first, w + offset[c].second);
			int x = t.first, y = t.second;
			if(matrix[x][y] == 'W' && !visited[x][y])
			{
			    visited[x][y] = true;
			    q.push(t);
			}
		    }
		}
	    }
	}
    }
    cout<<cont<<endl;
    return 0;
}
