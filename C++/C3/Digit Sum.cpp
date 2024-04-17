#include <iostream>

typedef long long lli;

using namespace std;

lli digit_sum(lli a)
{
    lli sum = 0;
    while(a != 0)
    {
	sum += a % 10;
	a /= 10;
    }
    return sum;
}

int main()
{
    lli n, m, sum;
    while(cin>>n>>m && m != 0)
    {
	sum = 0;
	for(lli a = n; a <= m; a++)
	    sum += digit_sum(a);
	cout<<sum<<endl;
    }
    return 0;
}
