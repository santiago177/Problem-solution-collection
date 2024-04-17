#include <iostream>
#include <cstdio>
#include <utility>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

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
    //freopen("Continents.in", "r", stdin);
    build();
    int n, m, c1, c2, land, max;
    bool besucht[25][25];
    char matrix[25][25];
    while(cin>>n>>m)
    {
	max = 0;
	memset(matrix, 0, 25*25);
	memset(besucht, 0, 25*25);
	string s;
	for(int a = 0; a < n; a++)
	{
	    cin>>s;
	    for(int b = 0; b < m; b++)
		matrix[a][b] = s[b];
	}
	cin>>c1>>c2;
	land = matrix[c1][c2];
	int cont;
	bool cap = false;
	for(int a = 0; a < n; a++)
	{
	    for(int b = 0; b < m; b++)
	    {
		cont = 0;
		if(matrix[a][b] == land && !besucht[a][b])
		{
		    queue<pii> q;
		    q.push(make_pair(a, b));
		    besucht[a][b] = true;
		    while(!q.empty())
		    {
			cont++;
			pii p = q.front();
			q.pop();
			if(p.first == c1 && p.second == c2)
			    cap = true;
			for(int c = 0; c < 4; c++)
			{
			    int x, y;
			    x = p.first + offset[c].first;
			    y = p.second + offset[c].second;
			    if(x < 0 || x >= n)
				break;
			    if(y < 0)
				y = m-1;
			    y %= m;
			    if(!besucht[x][y] && matrix[x][y] == land)
			    {
				besucht[x][y] = true;
				q.push(make_pair(x, y));
			    }
			}
		    }
		}
		if(cont > max && !cap)
		    max = cont;
		if(cap) 
		    cap = false;
	    }
	}
	cout<<max<<endl;
	getline(cin, s);
	cin.ignore();
    }
    return 0;
}
