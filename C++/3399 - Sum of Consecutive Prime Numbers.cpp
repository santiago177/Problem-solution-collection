#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

const int MAX = 10001;

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
    int n;
    while(cin >> n && n != 0)
    {
        int top = n;
        int cont = 0;
        int start = 2;
        while(!primes[top])
            top--;
        //cout << top << endl;
        if(top == n)
            cont ++;
        while(start < top)
        {
            int sum = 0;
            int s2 = start;
            while(sum < n)
            {
                if(primes[s2])
                    sum += s2;
                if(sum == n)
                    cont++;
                s2++;
                //cout<<"rec "<<sum<<endl;
                //system("pause");
            }
            start++;
            while(!primes[start] && start < top)
                start++;
                //cout <<"out"<<endl;
        }
        cout << cont << endl;
    }
    return 0;
}
