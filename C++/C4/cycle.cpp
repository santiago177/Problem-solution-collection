#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

int first;

int dfs(vb &visited, vi &steps, int n, vvi &graph, vi &pi)
{
   
    visited[n] = true;
    //cout<<"current "<<n<<endl;
    if(steps[n] == 2)
    {
	for(int a = 0; a < graph[n].size(); a++)
	{
	    if(graph[n][a] == first)
	    {
		//cout<<"si es "<<graph[n][a]<<endl;
		return n;
	    }
	}
	//cout<<"fuera"<<endl;
	return -1; 
    }
    for(int a = 0; a < graph[n].size(); a++)
    {
	if(!visited[graph[n][a]])
	{
	    steps[graph[n][a]] = steps[n] + 1;
	    pi[graph[n][a]] = n;
	    //cout<<"pi de "<<graph[n][a]<<" = "<<n<<endl;
	    int t = dfs(visited, steps, graph[n][a], graph, pi);
	    if(t != -1)
		return t;
	}
    }
    return -1;
}

int main()
{
    freopen("cycle.in", "r", stdin);
    int l;
    cin>>l;
    vector<string> inp;
    vector<vector<int> > graph(l);
    vi ans;
    bool exists = false;
    for(int a = 0; a < l; a++)
    {
	string s;
	cin>>s;
	for(int b = 0; b < s.size(); b++)
	{
	    if(s[b] == '1')
		graph[a].push_back(b);
	}
    }
    for(int a = 0; a < l; a++)
    {
	vector<bool> visited(l, false);
	vector<int> steps(l, 0);
	vi pi(l, -1);
	first = a;
	int t = dfs(visited, steps, a, graph, pi);
	if(t != -1)
	{
	    exists = true;
	    while(t != -1)
	    {
		ans.push_back(t);
		t = pi[t];
	    }
	    break;
	}
    }
    if(exists)
	printf("%d %d %d", ans[2]+1, ans[1]+1, ans[0]+1);
    else
	cout<<-1;
    return 0;
}
