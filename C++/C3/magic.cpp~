#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("magic.in", "r", stdin);
    freopen("magic.out", "w", stdout);
    int c;
    cin>>c;
    for(int z = 0; z < c; z++)
    {
	int r1, r2, matrix1[4][4], matrix2[4][4];
	cin>>r1;
	for(int a = 0; a < 4; a++)
	{
	    for(int b = 0; b < 4; b++)
		cin>>matrix1[a][b];
	}
	cin>>r2;
	for(int a = 0; a < 4; a++)
	{
	    for(int b = 0; b < 4; b++)
		cin>>matrix2[a][b];
	}
	int count = 0, ans = 0;
	r1--; r2--;
	for(int a = 0; a < 4; a++)
	{
	    for(int b = 0; b < 4; b++)
	    {
		if(matrix1[r1][a] == matrix2[r2][b])
		{
		    count++;
		    ans = matrix1[r1][a];
		}
	    }
	}
	//cout<<"count "<<count<<endl; 
	if(count == 0)
	    printf("Case #%d: Volunteer cheated!\n", z+1);
	else if(count == 1)
	    printf("Case #%d: %d\n", z+1, ans);
	else
	    printf("Case #%d: Bad magician!\n", z+1);
    }
    return 0;

}

