#include <iostream>
#include <cstdio>
#include <utility>

using namespace std;

void run(double tr[][402])
{
    tr[0][1] = 1;
    double sum;
    int pivot = 3;
    for(double a = 1; a < 402; a++)
    {
        sum = 0;
        for(double b = 2; b < pivot; b++)
        {
            tr[(int)a][(int)b] =a/b*tr[(int)a-1][(int)b-1];
            sum += tr[(int)a][(int)b];
        }
        pivot++;
        tr[(int)a][1] = 1-sum;
    }
}

int main()
{
    int n;
    double triangle[402][402];
    //cin>>n;
    run(triangle);
    for(int z = 0; z < 1; z++)
    {
        int d, m, k;
        //scanf("%d %d %d", &d, &m, &k);
        int pivot = 2;
        for(int a = 0; a < 20; a++)
        {
            for(int b = 1; b < pivot; b++)
                printf("%.2lf ", triangle[a][b]);
            cout<<endl;
            pivot++;
        }

    }
    return 0;
}
