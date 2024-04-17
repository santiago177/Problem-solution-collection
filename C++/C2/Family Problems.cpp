#include <iostream>

using namespace std;

char buchstaben[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U','V', 'W', 'X', 'Y', 'Z'};

int main()
{
    int n;
    while(cin>>n)
    {
	int cont = n, top = 1;
	while(cont > 1)
	{
	    int p = 0;
	    while(p <= top)
	    {
		p++;
		cont--;
	    }
	    top++;
	}
	cout<<"TERM "<<n<<" IS "<<buchstaben[(top%26)-1]<<endl;
    }
    return 0;
}
