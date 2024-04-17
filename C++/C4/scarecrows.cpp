#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    freopen("scarecrows.in", "r", stdin);
    int n;
    cin>>n;
    for(int z = 0; z < n; z++)
    {
	int trash, count = 0, total = 0, noc = 0;
	string s;
	cin>>trash;
	cin>>s;
	bool open = false, never = true;
	for(int a = 0; a < s.size(); a++)
	{
	   // cout<<s<<endl;
	    if(s[a] == '.')
	    {
		never = false;
		if(!open && noc != 1)
		{
		    total += ceil(count/3.0);
		    count = 0;
		}
		if(noc == 1)
		{
		    noc = 0;
		    count++;
		}
		count++;
		open = true;
	    }
	    else
	    {
		if(open == true)
		{
		    open = false;
		    noc = 0;
		}
		if(!never)
		    noc++;
	    }
	    //cout<<a<<" "<<count<<endl;
	}
//	cout<<"total "<<count<<endl;
	if(count > 0)
	{
	    total += ceil(count/3.0);
	}
	/*Case 1: 1

Case 2: 3

Case 3: 0*/
	cout<<"Case "<<z+1<<": "<<total<<endl;
    }
    return 0;
}
