#include <iostream>
#include <vector>
#include <queue>
#include <utility>

int operate(char o, int n, int m)
{
    if(o == '+')
	return n+m;
    if(o == '-')
	return n-m;
    if(o == '*')
	return n*m;
    return n/m;
}

int main()
{
    char op = {'+', '-', '*', '/'};
    int n;
    cin>>n;
    for(int z = 0; z < n; z++)
    {
	int t;
	cin>>t;
	vector<int> zahl(t);
	for(int a = 0; a < t; a++)
	    cin>>zahl[a];
	int current = 0;
	int res = 0;
	queue<int> q;
	while(1)
	{
	    
	}
    }
    return 0;
}
