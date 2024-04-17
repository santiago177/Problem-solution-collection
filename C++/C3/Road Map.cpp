#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    int n, r1, r2;
    cin>>n>>r1>>r2;
    vector<int> liste(n+1), neueliste(n+1);
    vector<vector<int> > graph(n+1);
    vector<bool> besucht(n+1);
    for(int a = 1; a <= n; a++)
    {
	if(a != r1)
	{
	    cin>>liste[a];
	    liste[a];
	    graph[liste[a]].push_back(a);
	    graph[a].push_back(liste[a]);
	}
	besucht[n] = false;
    }
    queue<int> q;
    q.push(r2);
    besucht[r2] = true;
    while(!q.empty())
    {
	int p = q.front();
	q.pop();
	for(int a = 0; a < graph[p].size(); a++)
	{
	    if(!besucht[graph[p][a]])
	    {
		neueliste[graph[p][a]] = p;
		besucht[graph[p][a]] = true;
		q.push(graph[p][a]);
	    }
	}
    }
    bool first = false;
    for(int a = 1; a <= n; a++)
    {
	if(!first && r2 != a)
	{
	    first = true;
	    cout<<neueliste[a];
	}
	else if(first && r2 != a)
	    cout<<" "<<neueliste[a];
    }
    return 0;
}
