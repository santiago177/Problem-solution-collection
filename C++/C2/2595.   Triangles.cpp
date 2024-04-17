#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main()
{
    int n, first, second, third;
    cin>>n;
    vector<long long> zahlen(n);
    bool all = true, none = true; 
    for(int a = 0; a < n; a++)
	cin>>zahlen[a];
    for(int a = 0; a < n; a++)
    {
	for(int b = a+1; b < n; b++)
	{
	    for(int c = b+1; c < n; c++)
	    {
		priority_queue<long long> pq;
		pq.push(-zahlen[a]);
		pq.push(-zahlen[b]);
		pq.push(-zahlen[c]);
		first = -pq.top();
		pq.pop();
		second = -pq.top();
		pq.pop();
		third = -pq.top();
		pq.pop();
		//cout<<"first = "<<first <<" second = "<<second<<" third = "<<third<<endl;
		if(first + second <= third)
		    all = false;
		else 
		    none = false;
	    }
	}
    }
    if(all ^ none || n < 3)
	cout<<"The set is rejected."<<endl;
    else
	cout<<"The set is accepted."<<endl;

    return 0;
}
