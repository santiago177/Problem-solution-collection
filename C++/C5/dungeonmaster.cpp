#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <typeinfo>

using namespace std;

template <class K, class J, class H> class triple
{
    public:
	K first;
        J second;
	H third;
	triple(K a, J b, H c)
	{
	    first = a;
	    second = b;
	    third = c;
	}
	triple()
	{
	}
	inline bool operator==(const triple<K, J, H> & lhs)
	{
	    return lhs.first == this.first && lhs.second == this.second && lhs.third == this.thid;
	}
};

void init(triple<int, int, int> *g)
{
    //z, x, y
    g[0] = triple<int, int, int>(0, 0, 1);
    g[1] = triple<int, int, int>(0, 1, 0);
    g[2] = triple<int, int, int>(0, 0, -1);
    g[3] = triple<int, int, int>(0, -1, 0);
    g[4] = triple<int, int, int>(1, 0, 0);
    g[5] = triple<int, int, int>(-1, 0, 0);
}

bool nice_pos(triple<int, int, int> t, int l, int r, int c)
{
    if(t.first < 0 || t.second < 0 || t.third < 0)
	return false;
    if(t.first >= l || t.second >= r || t.third >= c)
	return false;
    return true;
}

void print_triple(triple<int, int, int> t)
{
    cout<<t.first<<" "<<t.second<<" "<<t.third<<endl;
}

int main()
{
    //freopen("dungeonmaster.in", "r", stdin);
    int l, r, c;
    triple<int, int, int> offset[6];
    init(offset);
    while(cin>>l>>r>>c)
    {
	cin.ignore();
	if(l == 0 && r == 0 && c == 0)
	    break;
	bool visited[l][r][c], found = false;
	int times[l][r][c];
	memset(visited, false, sizeof(bool)*l*r*c);
	vector<vector<string> > maze(l, vector<string>(0));
	triple<int, int, int> start, end;	
	for(int a = 0; a < l; a++)
	{
	    string s;
	    for(int b = 0; b < r; b++)
	    {
		getline(cin, s);
		//cout<<"S "<<s<<endl;
		maze[a].push_back(s);
		for(int d = 0; d < c; d++)
		{
		    
		    if(s[d] == 'S')
		    {
			start = triple<int, int, int>(a, b, d);
		    }
		    if(s[d] == 'E')
		    {
			end = triple<int, int, int>(a, b, d);
		    }
		}
	    }
	    getline(cin, s);
	}
	/*for(int a = 0; a < l; a++)
	{
	    for(int b = 0; b < r; b++)
	    {
		for(int f = 0; f < c; f++)
		    cout<<maze[a][b][f];
		cout<<endl;
	    }
	    cout<<endl;
	}*/
	queue<triple<int, int, int> > q;
	q.push(start);
	visited[start.first][start.second][start.third] = true;
	times[start.first][start.second][start.third] = 0;
	while(!q.empty() && !found)
	{
	    triple<int, int, int> p = q.front();
	    q.pop();
	    for(int a = 0; a < 6; a++)
	    {
		//cout<<"start"<<endl;
		triple<int, int, int> t;
		t.first = p.first + offset[a].first;
		t.second = p.second + offset[a].second;
		t.third = p.third + offset[a].third;
		if(!nice_pos(t, l, r, c))
		    continue;
		//print_triple(t);
		char value;
		value = maze[t.first][t.second][t.third];
		if(value == '.' && !visited[t.first][t.second][t.third])
		{
		    q.push(t);
		    visited[t.first][t.second][t.third] = true;
		    times[t.first][t.second][t.third] = times[p.first][p.second][p.third] + 1;
		}
		if(value == 'E')
		{
		    //cout<<"found"<<endl;
		    //cout<<times[p.first][p.second][p.third]<<endl;
		    times[t.first][t.second][t.third] = times[p.first][p.second][p.third] + 1;
		    found = true;
		    break;
		}
	    }
	}
	if(!found)
	    cout<<"Trapped!"<<endl;
	else
	{
	    //cout<<"Escaped in "<<times[end.first][end.second][end.third]<<" minute(s)."<<endl;
	    cout<<"Escaped in "<<times[end.first][end.second][end.third]<<" minute(s)."<<endl;
	}
		
    }
    return 0;
}
