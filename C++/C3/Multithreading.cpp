#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, cont = 0;
    cin>>n;
    vector<int> zahlen(n);
    for(int a = 0; a < n; a++)
    {
	int pos;
	cin>>pos;
	zahlen[pos-1] = a; 
    }
    for(int a = 0; a < n; a++)
    {
	if(zahlen[a] > a)
	   cont++; 
    }
    cout<<cont;
    return 0;
}
