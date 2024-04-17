#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<vector<double> > lines;
    for(int z = 0; z < n; z++)
    {
	vector<double> za(4);
	double a, b, c, d;
	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
	za[0] = a;
	za[1] = b;
	za[2] = c;
	za[3] = d;
	lines.push_back(za);
    }
    double max = 0;
    for(int a = 0; a < n; a++)
    {
	for(int b = a+1; b < n; b++)
	{
	    double co = 0;
	    co = abs(lines[a][0]-lines[b][0]) + abs(lines[a][1]-lines[b][1])+ abs(lines[a][2]-lines[b][2]) + abs(lines[a][3]-lines[b][3]); 
	    if(co > max)
		    max = co;
	}
	
    }
    printf("%.3lf", max);
    return 0;
}
