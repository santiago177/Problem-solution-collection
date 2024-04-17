#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int z = 0; z < n; z++)
    {
        int p;
        long num, high;
        cin>>p>>num;
        high = num;
        while(num != 1)
        {
            if(num % 2 == 0)
                num /= 2;
            else
                num = num*3+1;
            if(num > high)
                high = num;
        }
        cout<<p<<" "<<high<<endl;
    }
    return 0;
}
