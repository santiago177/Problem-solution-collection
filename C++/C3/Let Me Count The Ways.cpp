#include <iostream>

using namespace std;

int main()
{
    int arten[300001];
    int werte[4];
    werte[0] = 5;
    werte[1] = 10;
    werte[2] = 25;
    werte[3] = 50;
    arten[1] = 1;
    for(int a = 2; a <= 30000; a++)
    {
	arten[a] = arten[a-1];
	for(int b = 0; b < 4; b++)
	{
	    if(arten[a-1] + werte[b] == a)
	    {
		cout<<"sum = "<<arten[a-1]+werte[b]<<endl;
		arten[a]++;
	    }
	}
	if(a == 10)
	    break;
    }
    int n;
    while(cin>>n)
    {
	// There are m ways to produce n cents change.
//There is only 1 way to produce n cents change. 
	if(arten[n] == 1)
	    cout<<"There is only 1 way to produce "<<n<<" cents change."<<endl;
	else
	    cout<<"There are "<<arten[n]<<" ways to produce "<<n<<" cents change."<<endl;
    }
    return 0;
}
