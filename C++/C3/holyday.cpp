#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int a = 0; a < n; a++)
    {
	int g, h, j;
	cin>>g>>h>>j;
	cout<<"Case "<<a+1<<": ";
	if(g > 20 || h > 20 || j > 20)
	    cout<<"bad"<<endl;
	else
	    cout<<"good"<<endl;
    }
    return 0;
}
