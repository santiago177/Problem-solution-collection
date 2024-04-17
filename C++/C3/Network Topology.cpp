#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

int main()
{
    int n, m;
    bool stern = true, ring = true, bus = true;
    cin>>n>>m;
    vector<pair<int, int> > input;
    set<int> possible;
    set<int> benutzt;
    for(int a = 0; a < m; a++)
    {
	int t, p;
	cin>>t>>p;
	input.push_back(make_pair(t, p));
    }
    if(n-1 == m)
    {
	ring = false;
	for(int a = 0; a < m; a++)
	{
	    int t, p;
	    t = input[a].first;
	    p = input[a].second;
	    if(possible.empty() && bus)
	    {
		possible.insert(t);
		possible.insert(p);
	    }
	    else
	    {
		if(benutzt.count(t) == 0 && benutzt.count(p) == 0 && bus)
		{
		    if(possible.count(t) != 0)
		    {
			benutzt.insert(t);
		    }
		    else
			possible.insert(t);
		    if(possible.count(p) != 0)
		    {
			benutzt.insert(p);
		    }
		    else
			possible.insert(p);
		}
		else
		{
		    bus = false;
		    break;
		}
	    }
	}
	if(bus && benutzt.size() != n-2)
	{
	    bus = false;
	}
	if(!bus)
	{
	    int share;
	    if(input[0].first == input[1].first || input[0].first == input[1].second)
		share = input[0].first;
	    else if(input[0].second == input[1].first || input[0].second == input[1].second)
		share = input[0].second;
	    else
		stern = false;
	    if(stern)
	    {
		for(int a = 2; a < m; a++)
		{
		    if(input[a].first != share && input[a].second != share)
		    {
			stern = false;
			break;
		    }
		}
	    }
	}
    }
    else if(n == m)
    {
	bus = false;
	stern = false;
	for(int a = 0; a < m; a++)
	{
	    int t, p;
	    t = input[a].first;
	    p = input[a].second;
	    if(possible.empty() && ring)
	    {
		possible.insert(t);
		possible.insert(p);
	    }
	    else
	    {
		if(benutzt.count(t) == 0 && benutzt.count(p) == 0 && ring)
		{
		    if(possible.count(t) != 0)
			benutzt.insert(t);
		    else
			possible.insert(t);
		    if(possible.count(p) != 0)
			benutzt.insert(p);
		    else
			possible.insert(p);
		}
		else
		{
		    ring = false;
		    break;
		}
	    }
	}
	if(benutzt.size() != n)
	   ring = false;
    }
    else
    {
	bus = false;
	stern = false;
	ring = false;
    }
    if(bus)
	cout<<"bus topology"<<endl;
    else if(stern)
	cout<<"star topology"<<endl;
    else if(ring)
	cout<<"ring topology"<<endl;
    else
	cout<<"unknown topology"<<endl;
    return 0;
}                         














