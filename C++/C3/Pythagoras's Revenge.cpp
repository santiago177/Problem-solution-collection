#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void proc(long long n, vector<long long> &factors)
{
    long long zahl = n * n;
    for(long long a = n; a <= zahl/2; a++)
    {
	cout<<"a = "<<a<<endl;
	if(zahl % a == 0)
	{
	    factors.push_back(a);
	    cout<<"factor = "<<a<<endl;
	}
    }
}

int main()
{
    long long n;
    while(cin>>n && n != 0)
    {
	int antwort = 0;
	long long square = n * n;
	vector<long long> factors;
	proc(n, factors);
        for(int a = 0; a < factors.size(); a++)
	{
	    double zahl = square / factors[a];
	    if(zahl - (long long) zahl <= 0)
	    {
		long long f, g;
		f = factors[a] + zahl;
		g = factors[a] - f;
		cout<<"g = "<<g<<endl;
		if(g > n)
		antwort++;
	    }
	}
	cout<<antwort<<endl;
    }
    return 0;
}
