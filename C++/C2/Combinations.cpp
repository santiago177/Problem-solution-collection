#include <iostream>

using namespace std;

long long factorial(long long n)
{
    if(n == 0 || n == 1)
	return 1;
    else
	return n * factorial(n-1);
}

int main()
{
    int n, m;
    while(cin>>n>>m && n != 0)
    {
	long long rest = n-m;
	long long buf = 1, ans;
	bool swap = false;
	if(rest > m)
	{
	    int temp;
	    temp = m;
	    m = rest;
	    rest = temp;
	    swap = true;
	}
	for(int a = n; a > m; a--)
	{
	    cout<<"a = "<<a<<endl;
	    buf *= a;
	cout<<buf<<endl;
	}
	ans = buf/factorial(rest);
	if(swap)
	cout<<n<<" things taken "<<rest<<" at a time is "<<ans<<" exactly."<<endl;
	else
	    cout<<n<<" things taken "<<m<<" at a time is "<<ans<<" exactly."<<endl;
    }
    return 0;
}
