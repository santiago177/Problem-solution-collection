#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    int n, values[3001];
    bool ex[3001];
    //freopen("10038 - Jolly Jumpers.in", "r", stdin);
    while(cin>>n)
    {
        bool jolly = true;
        for(int a = 0; a < n; a++)
        {
            scanf("%d", &values[a]);
            ex[a+1] = false;
        }
        for(int a = 0; a < n-1 && jolly; a++)
        {
            //cout<<"dif = "<<(int)(std::abs(values[a]-values[a+1]))<<endl;
            if((int)(std::abs(values[a]-values[a+1])) > n-1 || ex[(int)(std::abs(values[a]-values[a+1]))])
            {
                jolly = false;
                break;
            }
            ex[(int)(std::abs(values[a]-values[a+1]))] = true;
        }
        if(jolly)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }
    return 0;
}
