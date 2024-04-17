#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <sstream>
#include <utility>
#include <set>
#include <map>

using namespace std;

int main()
{
    //freopen("2090 - SPF.in", "r", stdin);
    int p, u, nc = 0;
    bool first = true;
    string s;
    while(1)
    {
	vector<int> netzwerk[1001];
	set<int> knoten;
	map<int, int> regist;
	while(getline(cin, s) && s != "0")
	{
	    stringstream st(s);
	    st >> p >> u;
	    /*cout<<"s = "<<s<<endl;
	    cout<<"p = "<<p<<" u = "<<u<<endl;*/
	    netzwerk[p].push_back(u);
	    netzwerk[u].push_back(p);
	    knoten.insert(p);
	    knoten.insert(u);
	}
	if(cin.eof() || knoten.empty())
	    break;
	if(!first)
	    cout<<endl;
	else
	    first = false;
	printf("Network #%d\n", ++nc);
	//cout<<"size = "<<knoten.size()<<endl;
	for(set<int>::iterator it = knoten.begin(); it != knoten.end(); it++)
	{
	    bool besucht[1001] = {0};
	    int taken = *it, subnetz = 0;
	    besucht[taken] = true;
	    for(set<int>::iterator it = knoten.begin(); it != knoten.end(); it++)
	    {
		//cout<<"current = "<<taken<<endl;
		if(!besucht[*it])
		{
		    //cout<<"in"<<endl;
		    queue<int> q;
		    q.push(*it);
		    besucht[*it] = true;
		    while(!q.empty())
		    {
			//cout<<"in2"<<endl;
			int p = q.front();
			q.pop();
			for(int a = 0; a < netzwerk[p].size(); a++)
			{
			    if(!besucht[netzwerk[p][a]])
			    {
				q.push(netzwerk[p][a]);
				besucht[netzwerk[p][a]] = true;
			    }
			}
		    }
		    subnetz++;

		}
	    }
	    //cout<<"subnetz = "<<subnetz<<endl;
	    if(subnetz > 1)
		regist[taken] = subnetz;
	}
/*Network #1
  SPF node 3 leaves 2 subnets

Network #2
  No SPF nodes

Network #3
  SPF node 2 leaves 2 subnets
  SPF node 3 leaves 2 subnets	*/
	if(!regist.empty())
	{
	    for(map<int, int>::iterator it = regist.begin(); it != regist.end(); it++)
		printf("  SPF node %d leaves %d subnets\n", it->first, it->second);
	}
	else
	    printf("  No SPF nodes\n");
	getline(cin, s);
    }
    return 0;
}
