#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("shkies.in", "r", stdin);
    freopen("shkies.out", "w", stdout);
    int n;
    cin>>n;
    for(int z = 0; z < n; z++)
    {
	double c, f, x, v, sum, s2, t1, t2, olds;
	cin>>c>>f>>x;
	v = 2.0;
	olds= 1<<30;
	sum = 0.0;
	int cont = 0;
	while(1)
	{
	    t1 = x / v;
	    t2 = c / v;
	    s2 = sum + t1;
	    if(s2 > olds)
		break;
	    sum += t2;
	    olds = s2;
	    v += f;
	}
	printf("Case #%d: %.7lf\n", z+1, olds);
    }
    return 0;
}
