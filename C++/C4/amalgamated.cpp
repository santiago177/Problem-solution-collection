#include <iostream>
#include <cstdio>
#include <utility>
#include <queue>
#include <cmath>

using namespace std;

int main()
{
//    cout<<sizeof(int)<<endl;
    vector<double> prices;
    int p, a, b, c, d, n;
    cin>>p>>a>>b>>c>>d>>n;
    for(int k = 1; k <= n; k++)
    {
	double buffer;
	buffer = p*(sin(a*k+b)+cos(c*k+d)+2);
	prices.push_back(buffer);
	//cout<<buffer<<" ";
    }
    //cout<<endl;
    double max = prices[0], fall = 0;
    for(int g = 1; g < n; g++)
    {
	if(prices[g] > max)
	{
	    max = prices[g];
	    continue;
	}
	double t = max - prices[g];
	if(t > fall)
	    fall = t;
    }
    printf("%.6lf", fall);
    return 0;
}
