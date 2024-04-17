#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class nodus
{
    public:
    vector<int> subs;
    int baus, min, sons, acc, id;
    nodus(int a)
    {
	id = a;
	baus = min = sons = acc = 0;
    }
};

int funcion(int n, vector<nodus> &w)
{
    int count = 0, t = 0;
    if(w[n].sons == 0)
	return 1;
    priority_queue<int> pq;
    for(int a = 0; a < w[n].subs.size(); a++)
	pq.push(-funcion(w[n].subs[a], w));
    while(t < w[n].min)
    {
	count += -pq.top();
	pq.pop();
	t++;
    }
    return count;
}

int main()
{
    int n;
    double t;
    while(cin>>n>>t && n != 0)
    {
	vector<nodus> workers(n+1, nodus(0));
	for(int a = 0; a < n; a++)
	{
	    int g;
	    cin>>g;
	    workers[a+1].id = a+1;
	    workers[a+1].baus = g;
	    workers[g].sons++;
	    workers[g].subs.push_back(a+1);
	}
	for(int a = 0; a < n+1; a++)
	{
	    double p = (double)(workers[a].sons)/ 100 * t;
	    if(p > int(p))
		workers[a].min = int(p+1);
	    else
		workers[a].min = int(p);
	}
	int ans = 0;
	ans = funcion(0, workers);
	cout<<ans<<endl;
    }
    return 0;
}
