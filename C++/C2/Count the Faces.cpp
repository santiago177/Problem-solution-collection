#include <iostream>

using namespace std;

int main()
{
    int vertices, edges;
    while(cin>>vertices>>edges)
    {
	char p, j;
	for(int a = 0; a < edges; a++)
	    cin>>p>>j;
	cout<<2-vertices+edges<<endl;
    }
    return 0;
}
