#include <iostream>
#include <cmath>
#include <set>

class nuple
{
    public:
    int zahlen[1001], size;
    nuple(int n)
    {
	size = n;
    }
    nuple()
    {}

    bool operator == (const nuple &n) const
    {
	if(n.size != size)
	    return false;
	for(int a = 0; a < size; a++)
	    if(zahlen[a] != n.zahlen[a])
		return false;
	return true;
    }
    bool operator < (const nuple &n) const
    {
	for(int a = 0; a < size; a++)
	{
	    if(zahlen[a] < n.zahlen[a])
		return true;
	    else if(zahlen[a] > n.zahlen[a])
		return false;
	}
    }
};


using namespace std;

int main()
{
    int n, ples, cases;
    bool ans;
    cin>>cases;
    for(int z = 0; z < cases; z++)
    {
	set<nuple> sset;
	cin>>n;
	nuple start(n), current;
	for(int a = 0; a < n; a++)
	    cin>>start.zahlen[a];
	current = start;
	while(27)
	{
	    nuple temp(n);
	    bool zerocheck = true;
	    for(int a = 0; a < n; a++)
	    {
		temp.zahlen[a] = abs(current.zahlen[a]-current.zahlen[(a+1)%n]);
		if(temp.zahlen[a] != 0)
		    zerocheck = false;
	    }
	    if(sset.find(temp) != sset.end())
	    {
		ans = false;
		break;
	    }
	    sset.insert(temp);
	    if(zerocheck)
	    {
		ans = true;
		break;
	    }
	    current = temp;
	}
	if(ans)
	    cout<<"ZERO"<<endl;
	else
	    cout<<"LOOP"<<endl;
    //    for(set<nuple>::iterator it = sset.begin(); it != sset.end(); it++)
    //    {
    //	for(int a = 0; a < (*it).size; a++)
    //	cout<<(*it).zahlen[a];
    //	cout<<endl;
    //    }
    }
    return 0;
}
