#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <windows.h>

using namespace std;

int main()
{
    freopen("conway.in", "r", stdin);
    pair<int, int> offset[8];
    offset[0] = make_pair(1, 0);
    offset[1] = make_pair(-1, 0);
    offset[2] = make_pair(0, 1);
    offset[3] = make_pair(0, -1);
    offset[4] = make_pair(1, 1);
    offset[5] = make_pair(-1, -1);
    offset[6] = make_pair(1, -1);
    offset[7] = make_pair(-1, 1);
    char player, truegrid[31][31], copy[31][31];
    cin>>player;
    for(int a = 0; a < 31; a++)
	truegrid[a][0] = truegrid[0][a] = truegrid[a][30] = truegrid[30][a] = '%';
    for(int a = 0; a < 29; a++)
    {
	string s;
	cin>>s;
	for(int b = 1; b <= 29; b++)
	    truegrid[a+1][b] = s[b-1];
    }
    for(int a = 0; a < 31; a++)
    {
	for(int b = 0; b < 31; b++)
	    cout<<truegrid[a][b];
	cout<<endl;
    }
    cout<<"couts"<<endl;
    cout<<truegrid[1][30]<<" "<<truegrid[1][29]<<endl;
    for(int a = 0; a < 500; a++)
    {
//	for(int f = 0; f < 31; f++)
//	{
//	    for(int g = 0; g < 31; g++)
//	    {
//		copy[f][g] = truegrid[f][g];
//		cout<<truegrid[f][g];
//	    }
//	    cout<<endl;
//	}
	for(int f = 0; f < 31; f++)
	{
	    for(int g = 0; g < 31; g++)
		copy[f][g] = truegrid[f][g];

	}
	for(int b = 1; b <= 29; b++)
	{
	    for(int c = 1; c <= 29; c++)
	    {
		int zaehlen = 0, white, black;
		white = black = 0;
		for(int d = 0; d < 8; d++)
		{
		    pair<int, int> t = make_pair(b+offset[d].first, c+offset[d].second);
		    if(truegrid[t.first][t.second] != '-' && truegrid[t.first][t.second] != '%')
		    {
			if(truegrid[t.first][t.second] == 'w')
			    white++;
			else
			    black++;
			zaehlen++;
		    }
		}
		if(zaehlen == 3)
		{
		    if(truegrid[b][c] == '-')
		    {
			if(white > black)
			    copy[b][c] = 'w';
			else
			    copy[b][c] = 'b';
		    }
		}
		if(zaehlen > 3 || zaehlen < 2)
		    copy[b][c] = '-';
	    }
	}
	for(int f = 0; f < 31; f++)
	{
	    for(int g = 0; g < 31; g++)
	    truegrid[f][g] = copy[f][g];
	}
    }
    for(int f = 0; f < 31; f++)
    {
	for(int g = 0; g < 31; g++)
	    cout<<truegrid[f][g];
	cout<<endl;
    }
return 0;
}
