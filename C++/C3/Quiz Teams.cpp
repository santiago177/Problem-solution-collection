#include <iostream>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

int gooby()
{

}

int main()
{
    int n;
    while(cin>>n && n != 0)
    {
	string s;
	int g, h;
	vector<pair<int, int> > liste;
	for(int a = 0; a < 2*n; a++)
	{
	    cin>>s>>g>>h;
	    liste.push_back(make_pair(g, h));
	}
    }
    return 0;
}
