#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>


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
	inline bool operator==(const triple<K, J, H> & lhs, const triple<K, J, H> & rhs)
	    return lhs.first == rhs.first && lhs.second == rhs.second && lhs.third == rhs.thid;
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

bool check(int a, int max)
{
    if(a < 0 || a >= max)
	return false;
    return true;
}

int main()
{
    int l, r, c;
    triple<int, int, int> offset[6];
    init(offset);
    while(cin>>l>>r>>c)
    {
	if(l == 0 && r == 0 && c == 0)
	    break;
	bool visited[l][r][c], found = false;
	int weight[l][r][c];
	memset(visited, false, sizeof(bool)*l*r*c);
	memset(weight, 0, sizeof(int)*i*j*c);
	vector<vector<vector<string> > > maze(l, vector<vector<string> > (r));
	triple<int, int, int> start, end;
	for(int a = 0; a < l; a++)
	{
	    string s;
	    for(int b = 0; b < r; b++)
	    {
		cin>>s;
		maze[a][r].push_back(s);
		for(int d = 0; d < c; d++)
		{
		    if(s[d] == 'S')
			start = triple<int, int, int>(a, b, d);
		    if(s[d] == 'E')
			end = triple<int, int, int>(a, b, d);
		}
	    }
	    cin>>s;
	}
	queue<triple<int, int, int> > q;
	q.insert(start);
	visited[start.first][start.second][start.third] = true;
	while(!q.empty())
	{
	    triple<int, int, int> p = q.front();
	    q.pop();
	    for(int a = 0; a < 6; a++)
	    {
		triple<int, int, int> t;
		t.first = p.first + offset[a].first;
		t.second = p.second + offset[a].second;
		t.third = p.third + offset[a].third;
		if(!check(t.first, l) || !check(t.second, r) || !check(t.third, c))
		    continue;
		char value = maze[t.first][t.second][t.third];
		if(value == '.')
		{
		    q.push(t);
		    visited[t.first][t.second][t.third] = true;
		}
		if(value == 'E')
		{
		    found = true
		}
		if(found)
		    break;
	    }
	}
		
    }
    return 0;
}
