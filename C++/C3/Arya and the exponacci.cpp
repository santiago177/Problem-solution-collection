#include <stdio.h>


typedef unsigned long long ull;

ull proc [1000001];

void fill()
{
    ull mod = 1000000007;
    proc[0] = 1;
    proc[1] = 2;
    int a;
    for(a = 2; a <= 1000001; a++)
	proc[a] = ((proc[a-1] % mod) * (proc[a-2] % mod)) % mod;
}


int main()
{
    fill();
    int n;
    scanf("%d", &n);
    int a;
    for(a = 0; a < n; a++)
    {
	ull p;
	scanf("%lld", &p);
	printf("%llu\n", proc[p]);
    }
    return 0;
}
