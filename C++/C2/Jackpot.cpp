#include <cstdio>
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

long long gcd(int a, int b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

long long lcm(int a, int b)
{
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

int main()
{
    int n, w;
    scanf("%d", &n);
    for(int z = 0; z < n; z++)
    {
        scanf("%d", &w);
        int wheels[5];
        for(int a = 0; a < w; a++)
            scanf("%d", &wheels[a]);
        long long d = std::accumulate(wheels, wheels + w, 1, lcm);
        if(d > 1000000000)
            printf("More than a billion.\n");
        else
        printf("%lld\n", d);
    }
    return 0;
}
