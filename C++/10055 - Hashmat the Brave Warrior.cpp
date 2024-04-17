#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    long long a, b, res;
    while(cin>>a>>b)
    {
        res = abs(b-a);
        printf("%lld\n", res);
    }
    return 0;
}
