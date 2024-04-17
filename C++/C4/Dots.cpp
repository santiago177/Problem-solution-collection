#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int z = 0; z < n; z++)
    {
	int s;
	cin>>s;
	double discr = sqrt(1 + 8*s);
	double dif = (double)((int)discr);
	if(discr - dif > 0.000000000001)
	    cout<<"No"<<endl;
	else
	    cout<<"Yes"<<endl;
    }
    return 0;
}
