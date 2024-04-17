#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
    //44721*
    unsigned long long upper_bound, size, lower_bound;
    long long n;
    bool found;
    while(cin>>n && n != -1)
    {
	upper_bound = sqrt(2*n);
	for(int a = upper_bound; a >= 1; a--)
	{
	    int t1, t2;
	    t1 = (2*n+a-(a*a));
	    t2 = 2*a;
	    if(t1 % t2 == 0)
	    {
	        found = true;
	        size = a;
	        lower_bound = t1/t2;
		//cout<<"lb = "<<lower_bound<<endl;
		break;
	    }
	}
//	8 = 8 + ... + 8
//15 = 1 + ... + 5
//35 = 2 + ... + 8
	printf("%lld = %llu + ... + %llu\n", n, lower_bound, lower_bound+size-1);
    }
    return 0;
}


