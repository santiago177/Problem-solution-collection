#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class tuple3
{
    public:
	int msg, bi, bf;
	tuple3(int a, int b, int c)
	{
	    msg = a;
	    bi = b; 
	    bf = c;
	}
};

class buffer
{
    public:
	vector<pair<int, int> > sizes;
	int sum;
	buffer()
	{
	    sum = 0;
	}
	void refresh()
	{
	    int s = 0;
	    for(int a = 0; a < sizes.size(); a++)
		s += sizes[a].first;
	    sum = s;
	}
	void erase(int id)
	{
	    for(int a = 0; a < sizes.size(); a++)
	    {
		if(sizes[a].second == id)
		    sizes.erase(sizes.begin() + a);
	    }
	}
	void insert(int a, int b)
	{
	    sizes.push_back(make_pair(a, b));
	}
};

int main()
{
    //freopen("Network.in", "r", stdin);
    int n, m, cas = 0;
    bool flag = false;
    while(cin>>n>>m && n != 0)
    {
	vector<int> sizes(n); 
	queue<tuple3> q;
	for(int a = 0; a < n; a++)
	    cin>>sizes[a];
	for(int a = 0; a < m; a++)
	{
	    int b, c, d;
	    cin>>b>>c>>d;
	    q.push(tuple3(b, c, d));
	}
	buffer bf;
	int max = 0;
	while(!q.empty())
	{
	    tuple3 p = q.front();
	    q.pop();
	    int dif = p.bf - p.bi + 1;
	    //cout<<"size = "<<sizes[p.msg-1]<<" dif = "<<dif<<endl;
	    if(sizes[p.msg-1] - dif == 0)
	    {
		bf.erase(p.msg);
	    }
	    else
	    {
		sizes[p.msg-1] -= dif;
		bf.insert(dif, p.msg);
		bf.refresh();
	    }
	    if(bf.sum > max)
	    {
		max = bf.sum;
		//cout<<"size "<<bf.sizes.size()<<endl;
		//cout<<"max = "<<max<<endl;
	    }
	}
	if(!flag)
	{
	    cout<<"Case "<<++cas<<": "<<max<<endl;
	    flag = true;
	}
	else
	{
	    cout<<"\nCase "<<++cas<<": "<<max<<endl;
	}
    }
    return 0;
}
