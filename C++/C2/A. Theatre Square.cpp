#include <iostream>

using namespace std;

int main()
{
    long long a, b, c, ans = 1;
    double coca, cocb;
    bool flag1, flag2;
    flag1 = flag2 = false;
    cin>>a>>b>>c;
    coca = a/c;
    cocb = b/c;
    ans *= (int)coca;
//    cout<<ans<<endl;
    ans *= (int)cocb;
    if(a%c != 0 && a >= c)
    {
        ans+=(int)cocb;
        flag1 = true;
    }
    if(b%c != 0 && b >= c)
    {
        ans+=(int)coca;
        flag2 = true;
    }
    if(flag1 && flag2)
        ans++;
    if(c > a || c > b)
        ans++;
    cout<<ans;
    return 0;
}
