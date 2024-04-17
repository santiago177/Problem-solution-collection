#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const long long MAX = 1000000000;

const long long lim = (int) sqrt(MAX);

vector<bool> primes(MAX,true);

long long  *pdivisor;

long long cont=0;

void criba(){

    primes[1] = false;

    for(long long i=2;i<=lim;i++){

        if(primes[i]){

            for(int j = 2*i; j<MAX; j=j+i)

                primes[j]=false;

        }

    }
}


int main()
{
    criba();
    long long cont = 1;
    for(long long a = 0; a < primes.size(); a++)
    {
        if(primes[a])
        {
            //printf("%lld\n", cont++);
            cout << cont++ <<endl;
        }
    }
    return 0;
}
