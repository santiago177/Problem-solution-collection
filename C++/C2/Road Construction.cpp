#include <iostream>
#include <set>

using namespace std;

int main()
{
    int nodes, edges, center;
    set<int> banned;
    cin>>nodes>>edges;
    for(int a = 0; a < edges; a++)
    {
	int c, b;
	cin>>c>>b;
	banned.insert(c);
	banned.insert(b);
    }
    for(int a = 1; a <= nodes; a++)
    {
	if(banned.find(a) == banned.end())
	{
	    center = a;
	    break;
	}
    }
    int cont = 0, nodec = 1;
    cout<<nodes-1<<endl;
    while(cont < nodes-1)
    {
	if(nodec == center)
	{   
	    nodec++;
	    continue;
	}
	cout<<center<<" "<<nodec<<endl;
	cont++;
	nodec++;
    }
    return 0;
}
