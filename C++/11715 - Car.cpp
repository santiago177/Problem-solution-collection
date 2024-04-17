#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

double quadratic(double a, double b, double c)
{
    //cout<<-c/b<<" "<<-c<<" "<<b<<endl;
    if(a == 0)
        return -c/b;
    double d1, r1, r2;
    d1 = sqrt(b*b-4.0*a*c);
    r1 = (-b+d1)/(2.0*a);
    r2 = (-b-d1)/(2.0*a);
//    cout<<a<<endl;
//    cout<<r2<<endl;
    if(r1 < r2)
        return r2;
    else
        return r1;
}

int main()
{
//    freopen("car.in", "r", stdin);
//    freopen("car.out", "w", stdout);
    int x, cont = 0;
    double a, b, c, r1, r2;
    while(cin>>x&&x!=0.0)
    {
        cin>>a>>b>>c;
        if(x == 0)  break;
        if(x == 1)
        {
            if(c == 0)
            {
                printf("Case %d: %.3lf %.3lf\n", ++cont, 0.000, 0.000);
                continue;
            }
            //cout<<a<<" "<<b<<" "<<c<<endl;
            r2 = (b-a)/c;
            r1 = a * c +(0.5*r2*c*c);
            //cout<<r1<<" "<<r2<<endl;
        }
        else if(x == 2)
        {
            if(c == 0)
            {
                printf("Case %d: %.3lf %.3lf\n", ++cont, 0.000, 0.000);
                continue;
            }
            r2 = ((b-a))/c;
            r1 = a * r2  +(0.5*c*r2*r2);
            //cout<<r1<<" "<<r2<<endl;
        }
        else if(x == 3)
        {
            r2 = quadratic(b/2.0, a, -c);
            r1 = a + b*r2;
            //cout<<r1<<" "<<r2<<endl;
        }
        else
        {
            r2 = quadratic(-b/2.0, a, -c);
            r1 = a - b * r2;
            //cout<<r1<<" "<<r2<<endl;
        }
        printf("Case %d: %.3lf %.3lf\n", ++cont, r1, r2);
    }
    return 0;
}
