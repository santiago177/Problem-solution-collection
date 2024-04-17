#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 1000000;

const int lim = (int) sqrt(MAX);

vector<bool> primes(MAX,true);

int  *pdivisor;

int cont=0;

void criba(){

    primes[1] = false;

    for(int i=2;i<=lim;i++){

        if(primes[i]){

            for(int j = 2*i; j<MAX; j=j+i)

                primes[j]=false;

        }

    }
}

int calc (int num)
{
    int div;
    while(num > 0)
    {
        if(primes[num])
            return num;
        if(num < 10)
            break;
        int sum = 0;
        //printf("numf %d\n", num);
        if(num < 10)
            div = 1;
        else if(num < 100)
            div = 10;
        else if(num < 1000)
            div = 100;
        else if(num < 10000)
            div = 1000;
        else if(num < 100000)
            div = 10000;
        else if(num < 1000000)
            div = 100000;
        while(div > 0)
        {
            sum += num/div;
            num -= (num/div)*div;
            div /= 10;
            //printf("suma %d\n", sum);
            //printf("num %d\n", num);
        }
        num = sum;

    }
    return -1;
}

using namespace std;

int main()
{
    criba();
    primes[0] = false;
    int c;
    int n;
    int root;
    while(scanf("%d",&n) && n != 0)
    {
        root = calc(n);
        if(root != -1)
            printf("%7d %7d\n", n, root);
        else
            printf("%7d    none\n", n);
    }
}
