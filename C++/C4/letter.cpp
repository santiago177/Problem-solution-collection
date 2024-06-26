#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
    freopen("letter.in", "r", stdin);
    int n, m;
    cin>>n>>m;
    vector<string> vec;
    int maxx, maxy, minx, miny;
    maxx = maxy = 0;
    minx = miny = 50;
    for(int a = 0; a < n; a++)
    {
	string s;
	cin>>s;
	vec.push_back(s);
    }
    for(int a = 0; a < n; a++)
    {
	for(int b = 0; b < m; b++)
	{
	    if(vec[a][b] == '*')
	    {
		if(a < minx)
		    minx = a;
		if(a > maxx)
		    maxx = a;
		if(b < miny)
		    miny = b;
		if(b > maxy)
		    maxy = b;
	    }
	}
    }
    for(int a = minx; a <= maxx; a++)
    {
	for(int b = miny; b <= maxy; b++)
	    cout<<vec[a][b];
	cout<<endl;
    }
    //cout<<minx<<" "<<miny<<" "<<maxx<<" "<<maxy<<endl;
    return 0;
}

