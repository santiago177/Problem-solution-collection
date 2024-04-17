#include <iostream>
#include <vector>
#include <utility>
#include <cstdio>
#include <deque>

using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;

int traverse(vvi &graph, vi &pi, int node, vb &visited)
{
    //cout<<node<<endl;
    for(int a = 0; a < graph[node].size(); a++)
    {
	if(visited[graph[node][a]])
	    return node;
	pi[graph[node][a]] = node;
	visited[graph[node][a]] = true;
	int t = traverse(graph, pi, graph[node][a], visited);
	if(t != -1)
	    return t;
	else
	    visited[graph[node][a]] = false;
    }
    return -1;
}

int main()
{
    //freopen("cycle.in", "r", stdin);
    int l, a1, a2, a3;
    cin>>l;
    vector<string> inp;
    vvi graph(l);
    deque<int> ans;
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
    vb visited(l, false);
    vi pi(l, -1);
    visited[0] = true;
    int t = traverse(graph, pi, 0, visited);
    //cout<<"out "<<t<<endl;
    int sav = t;
    bool found = false;
    if(t == -1)
	goto Jump;
    //cout<<"here"<<endl;
    do
    {
	ans.push_front(t);
	t = pi[t];
    }while(t != sav && t != -1);

    while(!found)
    {
	//cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
	for(int a = 0; a < graph[ans[2]].size(); a++)
	{
	    if(graph[ans[2]][a] == ans[0])
	    {
		a1 = ans[0];
		a2 = ans[1];
		a3 = ans[2];
		found = true;
	    }
	    break;
	}
	ans.erase(ans.begin()+1);
    }
Jump:
    if(!found)
	cout<<-1<<endl;
    else
	cout<<a1+1<<" "<<a2+1<<" "<<a3+1<<endl;
    return 0;
}
