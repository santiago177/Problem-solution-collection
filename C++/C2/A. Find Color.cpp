#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c;
    bool t, r, black = false;
    cin>>a>>b;
    c = a*b;
    if(c > 0)
        t = true;
    else
        t = false;
    double p = sqrt(a*a+b*b);
    int d = (int)p;
    if(p-d == 0)
        black = true;
    if(d % 2 == 0 && !black)
        r = true;
    else
        r = false;
    if(t)
        r = !r;
    if(!r || black)
        cout<<"black";
    else if(!black)
        cout<<"white";
    return 0;
}
