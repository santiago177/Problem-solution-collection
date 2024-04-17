#include <iostream>
#include <utility>
#include <cstdio>
#include <vector>

using namespace std;

class station
{
    public:
	vector<vector<int> > trains;
	vector<vector<int> > buses;
	int zone;
	station(int n)
	{
	    zone = n;
	}
	station()
	{
	    zone = 0;
	}
};

int main()
{
    freopen("gs.in", "r", stdin);
    int z, s;
    while(cin>>z>>s && z != 0)
    {
	int h, p;
	vector<station> graph(s);
	for(int a = 0; a < z; a++)
	{
	    cin>>p;
	    for(int b = 0; b < p; b++)
	    {
		cin>>h;
		graph[h-1].zone = a;
	    }
	}
	int t, b;
	cin>>t>>b;
	for(int a = 0; a < t; a++)
	{
	    cin>>p;
	    int prev;
	    if(a == 0)
	    {
		cin>>prev;
		continue;
	    }
	    for(int b = 0; b < p; b++)
	    {
		cin>>h;
		graph[h-1].trains.push_back(prev);
		graph[prev-1].trains.push_back(h-1);
		prev = h;
	    }
	}
	for(int a = 0; a < s; a++)
	    cout<<graph[a].zone<<endl;
    }
    return 0;
}
