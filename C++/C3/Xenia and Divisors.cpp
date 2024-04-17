#include <iostream>
#include <vector>

using namespace std;

class tuple3
{
    public:
    int erste, zweite, dritte;
    tuple3(int a, int b, int c)
    {
	erste = a;
	zweite = b;
	dritte = c;
    }
};

int main()
{
    int n1, n2, n3, n4, n6, n;
    bool moeglich = true;
    n1 = n2 = n3 = n4 = n6 = 0;
    vector<tuple3> v3;
    cin>>n;
    for(int a = 0; a < n; a++)
    {
	int p;
	cin>>p;
	if(p == 5 || p == 7)
	    moeglich = false;
	if(p == 1)
	    n1++;
	if(p == 2)
	    n2++;   
	if(p == 3)
	    n3++;
	if(p == 4)
	    n4++;
	if(p == 6)
	    n6++;
    }
    while(1)
    {
	if(n6 > 0)
	{
	    if(n3 > 0)
	    {
		if(n1 > 0)
		{
		    n6--; n3--; n1--;
		    v3.push_back(tuple3(1, 3, 6));
		}
		else
	    {
		moeglich = false;
		break;
	    }

	    }
	    else if(n2 > 0)
	    {
		if(n1 > 0)
		{
		    n6--; n2--; n1--;
		    v3.push_back(tuple3(1, 2, 6));
		}
		else
	    {
		moeglich = false;
		break;
	    }
	    }
	    else
	    {
		moeglich = false;
		break;
	    }
	}
	else if(n4 > 0)
	{
	    if(n2 > 0)
	    {
		if(n1 > 0)
		{
		    n1--; n4--; n2--;
		    v3.push_back(tuple3(1, 2, 4));
		}
		else
	    {
		moeglich = false;
		break;
	    }
	    }
	    else
	    {
		moeglich = false;
		break;
	    }
	}
	else if(n3 > 0 || n2 > 0 || n1 > 0)
	{
	    moeglich = false;
	    break;
	}
	else
	    break;
    }
    if(!moeglich)
	cout<<-1;
    else
    {
	for(int a = 0; a < v3.size(); a++)
	    cout<<v3[a].erste<<" "<<v3[a].zweite<<" "<<v3[a].dritte<<endl;
    }
    return 0;
}

