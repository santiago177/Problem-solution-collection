#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int cs;
    cin>>cs;
    for(int z = 0; z < cs; z++)
    {
	int n, m, counter = 0;
	cin>>n>>m;
	int p1 = 1, p2= 1, t;
	while(1)
	{
	    if(p1 == 1 && p2 == 1 && counter > 0)
		break;
	    t = (p1 + p2)%m;
	    p1 = p2;
	    p2 = t;
	    counter++;
	}
	cout<<n<<" "<<counter<<endl;
    }
    return 0;
}

