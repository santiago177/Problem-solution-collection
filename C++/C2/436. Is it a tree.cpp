#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main()
{
    vector<int> graph[10001];
    bool visited[10001] = {0}, from[500][500] = {0};
    int n, e, first;
    cin>>n>>e;
    for(int a = 0; a < e; a++)
    {
	int p1, p2;
	cin>>p1, p2;
	graph[p1].push_back(p2);
	graph[p2].push_back(p1);
	first = p1;
    }
    queue<int> q;
    q.push(first);
    bool notree = true;
    while(q.empty() && notree)
    {
	int p = q.front();
	q.pop();
	for(int a = 0; a < graph[p].size(); a++)
	{
	    if(!visited[graph[p][a]])
	    {
		q.push(graph[p][a]);
		visited[graph[p][a]] = true;
		from[graph[p][a]][p] = true;
		from[p][graph[p][a]] = true;
	    }
	    else
	    {
		if(visited[graph[p][a]] && !(from[p][graph[p][a]] || from[graph[p][a]][p]))
		{
		    notree = false;
		    break;
		}
	    }
	}
    }
    if(notree)
	cout<<"YES"<<endl;
    else
	cout<<"NO"<<endl;
    return 0;
}
