#include <iostream>

using namespace std;

int pay(int n, int m)
{
    if(m == 0)
	return n+1;
    if(n == 0 && m > 0)
    {
	return pay(1, m-1);
    }
    if(n > 0 && m > 0)
    {
	n = pay(n-1, m);
	return pay(n, m-1);
    }
}

int main()
{
    int k, n, m;
    cin>>k;
    for(int z = 0; z  < k; z++)
    {
	cin>>m>>n;
	cout<<pay(n, m)<<endl;
    }
    return 0;
}
