#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long a ,b, part;
    cin>>a>>b;
    double lg = log(b)/log(a);
    part = (int)lg;
    if(lg-part > 0)
        cout<<"NO";
    else
        cout<<"YES"<<endl<<part-1;
    return 0;
}
