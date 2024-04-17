#include <iostream>
#include <map>
#include <set>

using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int z = 0; z < n; z++)
    {
	set<int> db[10000];
	int lines, st;
	bool invalid = false;
	cin>>st>>lines;
	for(int a = 0; a < lines; a++)
	{
	    int s, sig;
	    cin>>s>>sig;
	    if(!invalid && db[s-1].find(sig) != db[s-1].end())
		invalid = true;
	    else
		db[s-1].insert(sig);
	}
	if(invalid)
		cout<<"Scenario #"<<z+1<<": impossible"<<endl;
	else
		cout<<"Scenario #"<<z+1<<": possible"<<endl;
    }
    return 0;
}
