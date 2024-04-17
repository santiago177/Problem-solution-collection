#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> pyramid[9];
void init()
{
    for(int a = 0; a < 9; a++)
	pyramid[a] = vector<int>(9 - a, -1);
}

int main()
{
    //freopen("Add Bricks in The Wall.in", "r", stdin);
    init();
    int n;
    cin>>n;
    for(int z = 0; z < n; z++)
    {
	for(int a = 8; a >= 0; a-=2)
	{
	    for(int b = pyramid[a].size()-1; b >= 0; b -= 2)
		cin>>pyramid[a][b];
	}
	for(int a = 7; a >= 0; a -= 2)
	{
	    for(int b = 0; b < pyramid[a].size(); b += 2)
	    {
		pyramid[a][b] = (pyramid[a+1][b] + pyramid[a-1][b] - pyramid[a-1][b+2])/2;
		pyramid[a][b+1] = pyramid[a+1][b] - pyramid[a][b];
		pyramid[a-1][b+1] = pyramid[a][b] - pyramid[a-1][b];
	    }
	}
	for(int a = 8; a >= 0; a--)
	{
		for(int b = pyramid[a].size()-1; b >= 0; b--)
		{
		    if(b != 0)
		    cout<<pyramid[a][b]<<" ";
		    else
		    cout<<pyramid[a][b];
		}
		cout<<endl;
	}
    }
    
    return 0;
}
