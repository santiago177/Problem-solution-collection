#include <iostream>

using namespace std;

typedef long long ll;

ll matrix[100][100];
ll values[100][100];

int main()
{
    int n;
    ll max = -1<<30;
    cin>>n;
    for(int a = 0; a < n; a++)
    {
	int sum = 0;
	for(int b = 0; b < n; b++)
	{
	    cin>>matrix[a][b];
	    if(a == 0)
	    {
		sum += matrix[a][b];
		values[a][b] = sum;
	    }
	    else
	    {
		sum += matrix[a][b];
		values[a][b] = sum + values[a-1][b];
	    }
	    if(values[a][b] > max)
		max = values[a][b];
	}
    }
    for(int a = 0; a < n; a++)
    {
	for(int b = 0; b < n; b++)
	{
	    for(int c = a; c < n; c++)
	    {
		for(int d = b; d < n; d++)
		{
		    int calc = 0;
		    calc = values[c][d];
		    if(b != 0)
			calc -= values[c][b-1];
		    if(a != 0)
			calc -= values[a-1][d];
		    if(a != 0 && b != 0)
		        calc += values[a-1][b-1];
		    //cout<<"a = "<<a<<" b = "<<b<<" c = "<<c<<" d = "<<d<<endl;
		    //cout<<"calc = "<<calc<<endl;
		    if(calc > max)
			max = calc;
		}
	    }
	}
    }
    /*cout<<"------------"<<endl;
    for(int a = 0; a < n; a++)
    {
	for(int b = 0; b < n; b++)
	    cout<<values[a][b]<<" ";
	cout<<endl;
    }*/
    cout<<max;
    return 0;
}
