#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

string d, m;
int memo[50][50];

bool isMultiple(double b, double a)
{
    if(int(a) == 0 || int(b) == 0)
	return true;
    return double(b / a) == (int)(b / a);
}

void print_memo()
{
    for(int a = 0; a < 50; a++)
    {
	for(int b = 0; b < 50; b++)
	    cout<<memo[a][b];
	cout<<endl;
    }
}


int S(int dn, int mn)
{
    if(memo[dn][mn] != -1)
    	return memo[dn][mn];
    //print_memo();
    int a, b;
    a = d[dn] - '0';
    b = m[mn] - '0';

    //cout<<"current "<<a<<" "<<b<<endl;
    if(dn == 0 || mn == 0)
    {
	if(isMultiple(b, a))
	    return 1;
	else
	    return 0;
    }
    if(isMultiple(b, a))
    {
	int a2, b2;
	a2 = d[dn-1] - '0';
	b2 = m[mn-1] - '0';
	if(isMultiple(b2, a2))
	{
	    memo[dn][mn] = 1 + S(dn-1, mn-1);
	    return memo[dn][mn];
	}
	else
	{
	    memo[dn][mn] = max(S(dn, mn-1), S(dn-1, mn));
	    return memo[dn][mn];
	}
    }
    else
    {
	memo[dn][mn] = max(S(dn, mn-1), S(dn-1, mn));
        return memo[dn][mn];
    }
}


int main()
{
    memset(memo, -1, sizeof(int)*50*50);
    //print_memo(); 
    string s1, s2;
    cin>>s1>>s2;
    d = s1;
    m = s2;
    cout<<S(s1.size() - 1, s2.size() - 1)<<endl;
    print_memo();
    return 0;
}
