#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    int b, n;
    while(cin>>b>>n && b != 0)
    {
	int cont = 2, dif, prev = b - 1, a = 1;
	dif = abs(pow(2, n) - b);
	while(dif < prev)
	{
	    cout<<"prev = "<<prev<<" dif = "<<dif<<endl;
	    prev = dif;
	    dif = abs(pow(cont, n) - b);
	    cout<<"ndif = "<<dif<<endl;
	    a = cont;
	    cont++;
	}
	cout<<a<<endl;
    }
    return 0;
}
