#include <iostream>

using namespace std;

int main()
{
    int n;
    string s;
    cin>>s;
    cin>>n;
    for(int z = 0; z < n; z++)
    {
	int lb, ub, cont = 0;
	cin>>lb>>ub;
	lb--; ub--;
	for(int a = lb; a < ub; a++)
	{
	    if(s[a] == s[a+1])
		cont++;
	}
	cout<<cont<<endl;
    }

}
