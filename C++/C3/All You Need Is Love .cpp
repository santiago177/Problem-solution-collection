#include <iostream>
#include <cmath>

using namespace std;

int euclid(long long a, long long b)
{
    int t;
    while(b != 0)
    {
	t = b;
	b = a%t;
	a = t;
    }
    return a;
}

long long todec(string s)
{
    int pw = s.size() - 1;
    long long ant = 0;
    for(int a = 0; a < s.size(); a++)
	ant += pow(2, pw--)*(s[a]-'0');
    return ant;
}

int main()
{
    int n;
    cin>>n;
    for(int z = 0; z < n; z++)
    {
	string g, h;
	cin>>g>>h;
	long long e, r;
	e = todec(g); r = todec(h);
	if(euclid(e, r) == 1)
	    cout<<"Pair #"<<z+1<<": Love is not all you need!"<<endl;
	else
	    cout<<"Pair #"<<z+1<<": All you need is love!"<<endl;
	
    }
    return 0;
}
