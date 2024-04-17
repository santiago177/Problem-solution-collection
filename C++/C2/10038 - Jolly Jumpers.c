#include <stdio.h>
#include <math.h>

int main()
{
    freopen("10038 - Jolly Jumpers.in", "r", stdin);
    int n, values[3001];
    while(scanf("%d", &n) != 0)
    {
        char ex[3001] = {0}, jolly = 1;
        int a, cont = 0;;
        for(a = 0; a < n; a++)
            scanf("%d", &values[a]);
        for(a = 0; a < n-1 && jolly; a++)
        {
            if((int)(abs(values[a]-values[a+1])) > n-1 || ex[(int)(abs(values[a]-values[a+1]))])
            {
                jolly = 0;
                break;
            }

            ex[(int)(abs(values[a]-values[a+1]))] = 1;
        }
        if(jolly)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }
    return 0;
}
