#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 1299710;

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
int main()
{
    criba();
    int x;
    while(scanf("%d", &x) && x != 0)
    {
            int c1 = x, cf = 0;
            while(!primes[c1--])
                cf++;
            c1 = x;
            while(!primes[c1++])
                cf++;
            printf("%d\n", cf);
    }
    return 0;
}
