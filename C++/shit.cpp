#include <iostream>
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
    freopen("primelist.out","w",stdout);
    cout<<"int primeList[] = {";
    for(int a = 0; a < primes.size(); a++)
    {
        if(primes[a])
            cout<<a<<", ";
    }
    cout<<"};";
    return 0;
}
