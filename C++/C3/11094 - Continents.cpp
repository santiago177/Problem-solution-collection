#include <iostream>
#include <cstdio>
#include <utility>
#include <queue>
#include <vector>

using namespace std;

class 3tuple
{
    int x, y, size;
    3tuple(int x, int y, int size)
    {
	x = *this.x ;
	y = *this.y;
	size = *this.size;
    }
};

typedef pair<int, int> pii;

pii offset[4];

void build()
{
    offset[0] = make_pair(0, 1);
    offset[1] = make_pair(0, -1);
    offset[2] = make_pair(1, 0);
    offset[3] = make_pair(-1, 0);
}

int main()
{
    build();
    int n, m, ix, iy;
    bool visited[24][24] = {0};
    char key;
    cin>>n>>m;
    char karte[24][24];
    for(int a = 0; a < n; a++)
            karte[0][a] = karte[a][0] = karte[n-1][a] = karte[a][m-1] = '$';
    for(int a = 0; a < n; a++)
    {
	string s;
	getline(cin, s);
	for(int b = 0; b < m; b++)
	    karte[a+1][b+1] = s[b];
    }
    cin>>ix>>iy;
    key = karte[ix+1][iy+1];
    pii start = make_pair(ix+1, iy+1);
    queue<pii> q;
    q.push(start);
    visited[start.first][start.second] = true;
    while(!q.empty())
    {
	pii p = q.front();
	q.pop();
	for(int a = 0; a < 4; a++)
	{
	    pii t = make_pair(p.first + offset[a].first, p.second + offset[a].second);
	    if(karte[t.first][t.second] == )
	}
    }
    return 0;
}
