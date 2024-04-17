#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;
int main()
{
    map<int, int> count;
    vector<double> i;
    priority_queue<int> highest;
    int n, m;
    double t;
    cin>>n;
    for(int a = 0; a < n; a++)
    {
	cin>>t;
	i.push_back(t);
    }
    cin>>m;
    for(int a = 0; a < m; a++)
    {
	cin>>t;
	//j.push_back(t);
	for(int b = 0; b < n; b++)
	{
	    double quotient = t / i[b];
	    int p = t / i[b];
	    if(quotient - p == 0)
	    {
		highest.push(p);
		if(count.find(p) == count.end())
		    count[p] = 1;
		else
		    count[p]++;
	    }
	}
    }

    cout<<count[highest.top()];
    return 0;
}