#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >>n;
    for(int z = 0; z < n; z++)
    {
        double num;
        scanf("%lf", &num);
        num *= 567;
        num /= 9;
        num += 7492;
        num *= 235;
        num /= 47;
        num -= 498;
        cout<<abs((int)(num/10)%10)<<endl;
    }
    return 0;
}
