#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c, e1, e2, e3;
    cin>>a>>b>>c;
    e1 = sqrt(a*b/c);
    e2 = sqrt(a*c/b);
    e3 = sqrt(c*b/a);
    cout<<e1*4+e2*4+e3*4<<endl;
    return 0;
}
