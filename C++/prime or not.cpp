#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

long long modularMul(long long res, long long e, long long m);

long long modexp(long long b, long long e, long long m)
{
    long long res = 1;
    while(e > 0)
    {
        if(e % 2 == 1)
            res = modularMul(res, b, m);
         e  = e >> 1;
         b = modularMul(b, b, m);
    }
    return res;
}

long long modularMul(long long a,long long b,long long mod){
long long x = 0,y = a % mod;
while(b > 0){
if(b % 2 == 1)
x = (x + y) % mod;
y = (y * 2) % mod;
b  = b >> 1; // b /= 2
}
return x % mod;
}

bool fermat(long long p)
{
    for(int a = 0; a < 4; ++a)
    {
        long long r = rand() % (p-1) + 1;
        if(modexp(r, p-1, p) == 1)
            continue;
        else
            return false;
    }
    return true;
}

int main()
{
    srand (time(NULL));
    int n;
    cin >> n;
    for(int a = 0; a < n; ++a)
    {
        long long p;
        cin >> p;
        if(fermat(p))
            cout << "YES" <<endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
