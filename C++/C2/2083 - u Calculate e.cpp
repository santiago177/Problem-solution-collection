#include <cstdio>


using namespace std;

int fact(int n)
{
    if(n == 1 || n == 0)
        return 1;
    else
        return n * fact(n-1);
}

int main()
{
    printf("n e\n- -----------\n");
    double sum = 2.5;
    printf("0 1\n");
    printf("1 2\n");
    printf("2 2.5\n");
    for(int a = 3; a < 10; a++)
    {
        sum += 1.0 / fact(a);
        printf("%d %.9lf\n", a, sum);
    }
    return 0;
}
