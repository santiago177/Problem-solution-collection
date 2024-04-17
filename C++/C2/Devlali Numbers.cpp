#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

bool prime[10000000];
bool devlali[10000000];
int sum(int n);
int top;
void criba()
{
    memset(prime, true, 10000000);
    top = sqrt(10000000);
    top = sqrt(10000000);
    prime[0] = prime[1] = false;
    for(int a = 2; a <= top; a++)
    {
	for(int b = 2; b <= top; b++)
	    prime[a*b] = false;
    }
}

void dev()
{
    memset(devlali, true, 10000000);
    long top = 1000000000/2;
    for(int a = 1; a <= top; a++)
    {
	if(sum(a) <= 1000000)
	devlali[sum(a)] = false;
    }
}


int sum(int n)
{
    int sum = n;
    while(n != 0)
    {
	sum += n%10;
	n /= 10;
    }
    return sum;
} 

int main()
{
    criba();
    dev();
    int q;
    cin>>q;
    for(int a = 0; a < q; a++)
    {
	int h, j, zahl = 0;
	cin>>h>>j;
	for(int b = h; b <= j; b++)
	{
	    if(devlali[b] && prime[b])
		zahl++;
	}
	cout<<zahl<<endl;
    }
    return 0;
}
