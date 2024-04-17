#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <cmath>

using namespace std;

const int MAX = 31622;

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

    cont = 1;

    for(int i=3;i<MAX;i+=2)

        if(primes[i]) cont++;

    pdivisor = new int[cont];

    cont = 1;

    pdivisor[0]=2;

    for(int i=3;i<MAX;i+=2)

        if(primes[i])

            pdivisor[cont++] = i;

}

int main()
{
    criba();
    string pairs;
    map<pair<int, int>, int> query;
    int a = 1;
    bool impr = false;
    int lim = 1, comp = 0;
    int twice = 0;
    bool b, c;
    bool first = false;
    b = c = true;
    int x = 0, y = 0;
    while(a < 10001)
    {
        if(primes[a])
        {
            if(b && c)
            {
                query[make_pair(x++, y)] = a;
                comp++;
            }
            if(b && !c)
            {
                query[make_pair(x, y++)] = a;
                comp++;
            }
            if(!b && c)
            {
                query[make_pair(x--, y)] = a;
                comp++;
            }
            if(!b && !c)
            {
                query[make_pair(x, y--)] = a;
                comp++;
            }
            if(comp == lim)
            {
                if(twice < 1)
                {
                    twice++;
                }
                else
                {
                    twice = 0;
                    lim++;
                }
                comp = 0;
                if(b && c)
                    c = false;
                else if(b && !c)
                {
                    b = false;
                    c = true;
                }
                else if(!b && c)
                    c = false;
                else if(!b && !c)
                {
                    c = true;
                    b = true;
                }
            }
        }
        a++;
    }
    comp = 0;
    while(1)
    {
        cin >> x;
        if(x == -999)
            break;
        cin >> y;
        if(impr)
        {
            cout<<endl;
            cout<<"Case "<<++comp<<": The prime at location ("<<x<<","<<y<<") is "<<query[make_pair(x, y)]<<"."<<endl;
        }
        else
        {
            cout<<"Case "<<++comp<<": The prime at location ("<<x<<","<<y<<") is "<<query[make_pair(x, y)]<<"."<<endl;
            impr = true;
        }
    }
    return 0;
}




