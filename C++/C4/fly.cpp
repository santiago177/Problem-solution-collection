#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int cs;
    cin>>cs;
    for(int z = 0; z < cs; z++)
    {
	int n;
        double d, v1, v2, v3;
	cin>>n>>d>>v1>>v2>>v3;
	double t = d/(v1+v2);
	double ans = v3*t;
	printf("%d %.2lf\n", n, ans);
    }
    return 0;
}
