#include <iostream>

using namespace std;

int main()
{
    long long n, m, k;
    cin>>n;
    int c = n % 10;
    m = (n/100)*10+c;
    k = n / 10;
    if(n > m && n > k)
        cout<<n;
    else if(m > n && m > k)
        cout<<m;
    else
        cout<<k;
    return 0;
}
